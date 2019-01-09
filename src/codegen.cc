#include "codegen.hh"

#include <fstream>
#include <sstream>
#include <vector>

namespace explain {

CodeGenerator::CodeGenerator(MessageIssuer *mi, const std::string& ModuleName)
    : mi(mi), Builder(llvm::IRBuilder<>(Context)), V(nullptr)
{
    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    std::string Error;
    auto TargetTriple = llvm::sys::getDefaultTargetTriple();
    auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, Error);

    if (!Target)
        mi->fatal_error(Error);

    auto CPU = "generic";
    auto Features = "";

    llvm::TargetOptions opt;
    auto RM = llvm::Optional<llvm::Reloc::Model>();
    TargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    Module = std::make_unique<llvm::Module>(ModuleName, Context);
    Module->setDataLayout(TargetMachine->createDataLayout());
    Module->setTargetTriple(TargetTriple);

    FPM = std::make_unique<llvm::legacy::FunctionPassManager>(Module.get());
    // Promote `Alloca`s to registers (mem2reg).
    FPM->add(llvm::createPromoteMemoryToRegisterPass());
    // Peephole optimizations and bit-twiddling optzns. (Cool abbreviation, huh?)
    FPM->add(llvm::createInstructionCombiningPass());
    // Re-associate expressions.
    FPM->add(llvm::createReassociatePass());
    // Eliminate common subexpressions.
    FPM->add(llvm::createGVNPass());
    // Simplify control flow graph (delete unreachable blocks, etc).
    FPM->add(llvm::createCFGSimplificationPass());

    FPM->doInitialization();

    // Set up printf and scanf externs

    std::string IFmtS = "%lf";
    llvm::Constant *IFmtSC = llvm::ConstantDataArray::getString(Context, IFmtS, true);
    llvm::ArrayType *IFmtTy = llvm::ArrayType::get(llvm::Type::getInt8Ty(Context), IFmtS.size() + 1);
    InputFmt = new llvm::GlobalVariable(*Module, IFmtTy, /* isConstant = */ true,
            llvm::GlobalValue::InternalLinkage, /* Initializer = */ IFmtSC, "ifmt", /* InsertBefore = */ nullptr,
            llvm::GlobalValue::NotThreadLocal, /* AddressSpace = */ 0, /* isExternallyInitialized = */ 0);

    std::string OFmtS = "%lf\x0A";
    llvm::Constant *OFmtSC = llvm::ConstantDataArray::getString(Context, OFmtS, true);
    llvm::ArrayType *OFmtTy = llvm::ArrayType::get(llvm::Type::getInt8Ty(Context), OFmtS.size() + 1);
    OutputFmt = new llvm::GlobalVariable(*Module, OFmtTy, /* isConstant = */ true,
            llvm::GlobalValue::InternalLinkage, /* Initializer = */ OFmtSC, "ofmt", /* InsertBefore = */ nullptr,
            llvm::GlobalValue::NotThreadLocal, /* AddressSpace = */ 0, /* isExternallyInitialized = */ 0);

    std::vector<llvm::Type *> CommonArgsTy { llvm::Type::getInt8PtrTy(Context) };
    llvm::FunctionType *CommonTy = llvm::FunctionType::get(llvm::Type::getInt32Ty(Context), CommonArgsTy,
            /* isVarArg = */ true);

    Scanf = llvm::Function::Create(CommonTy, llvm::Function::ExternalLinkage, "scanf", Module.get());
    Printf = llvm::Function::Create(CommonTy, llvm::Function::ExternalLinkage, "printf", Module.get());
}

void CodeGenerator::emitObject(const std::string& Filename)
{
    std::error_code EC;
    llvm::raw_fd_ostream dest(Filename, EC, llvm::sys::fs::F_None);

    if (EC)
        mi->fatal_error("could not open file: " + EC.message());

    llvm::legacy::PassManager pass;
    auto FileType = llvm::TargetMachine::CGFT_ObjectFile;
    if (TargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType))
        mi->fatal_error("TargetMachine can't emit a file of this type");

    pass.run(*Module);
    dest.flush();
}

void
CodeGenerator::emitDriver(const std::string& Filename)
{
    std::ofstream out(Filename);

    out << "#include <stdio.h>\n"
           "extern double xpln_main(void);\n"
           "int main(int argc, char **argv) {\n"
           "    double result = xpln_main();\n"
           "    return (int) result;\n"
           "}\n";
    out.flush();
}

void
CodeGenerator::printModule(const std::string& Filename)
{
    std::error_code EC;
    llvm::raw_fd_ostream dest(Filename, EC, llvm::sys::fs::F_None);

    if (EC)
        mi->fatal_error("could not open file: " + EC.message());

    dest << *Module;
    dest.flush();
}

llvm::AllocaInst *
CodeGenerator::EmitEntryBlockAlloca(const std::string &VarName)
{
    llvm::IRBuilder<> TmpBuilder(&currentFunction->getEntryBlock(),
            currentFunction->getEntryBlock().begin());

    return TmpBuilder.CreateAlloca(llvm::Type::getDoubleTy(Context), nullptr, VarName);
}

void
CodeGenerator::visit(AST::Root *root)
{
    for (auto& f : root->funcDecls)
        f->accept(*this);

    std::string str;
    llvm::raw_string_ostream OS(str);
    if (llvm::verifyModule(*Module, &OS))
    {
        OS.flush();
        mi->error("llvm::verifyModule failed: " + str);
        return;
    }
}

void
CodeGenerator::visit(AST::BlockStmt *block)
{
    for (auto& s : block->stmts)
        s->accept(*this);
}

void
CodeGenerator::visit(AST::FuncDeclArgs *args)
{
    ;
}

void CodeGenerator::visit(AST::FuncCallArgs *args)
{
    ;
}

void
CodeGenerator::visit(AST::Entry *entry)
{
    ;
}

void
CodeGenerator::visit(AST::Stmt *stmt)
{
    ;
}

void
CodeGenerator::visit(AST::FuncDecl *decl)
{
    std::string FuncName = decl->ident;
    std::vector<std::string> ArgNames = decl->args->idents;
    std::vector<llvm::Type *> ArgTypes(ArgNames.size(), llvm::Type::getDoubleTy(Context));
    llvm::FunctionType *FT = llvm::FunctionType::get(llvm::Type::getDoubleTy(Context), ArgTypes,
            /* isVarArg = */ false);
    llvm::Function *F = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, FuncName, Module.get());
    currentFunction = F;

    unsigned i = 0;
    for (auto& Arg : F->args())
        Arg.setName(ArgNames[i++]);

    llvm::BasicBlock *EntryBB = llvm::BasicBlock::Create(Context, "entry", F);
    Builder.SetInsertPoint(EntryBB);
    currentBasicBlock = EntryBB;

    // Install function arguments to `Locals`
    Locals.clear();
    for (auto& Arg : F->args())
    {
        llvm::AllocaInst *Alloca = EmitEntryBlockAlloca(Arg.getName());
        Builder.CreateStore(&Arg, Alloca);
        Locals[Arg.getName()] = Alloca;
    }

    decl->body->accept(*this);

    std::string str;
    llvm::raw_string_ostream OS(str);
    if (llvm::verifyFunction(*F, &OS))
    {
        OS.flush();
        mi->error("llvm::verifyFunction failed for function " + FuncName + ": " + str);
        F->eraseFromParent();

        return;
    }

    FPM->run(*F);
}

void
CodeGenerator::visit(AST::AssignmentStmt *stmt)
{
    std::string VarName = stmt->ident;

    stmt->expr->accept(*this);
    llvm::Value *AssignedValue = V;
    if (!AssignedValue)
        return;

    llvm::Value *Variable = Locals[VarName];
    if (!Variable)
    {
        llvm::AllocaInst *Alloca = EmitEntryBlockAlloca(VarName);
        Builder.CreateStore(AssignedValue, Alloca);
        Locals[VarName] = Alloca;
    }
    else
    {
        Builder.CreateStore(AssignedValue, Variable);
    }
}

void
CodeGenerator::visit(AST::IfStmt *stmt)
{
    stmt->cond->accept(*this);
    llvm::Value *Cond = V;
    if (!Cond)
        return;

    llvm::Value *NeqZero = Builder.CreateFCmpONE(Cond, llvm::ConstantFP::get(Context, llvm::APFloat(0.0)));

    llvm::BasicBlock *ThenBB = llvm::BasicBlock::Create(Context, "then", currentFunction);
    llvm::BasicBlock *ElseBB = llvm::BasicBlock::Create(Context, "else", currentFunction);
    llvm::BasicBlock *MergeBB = nullptr;

    Builder.CreateCondBr(NeqZero, ThenBB, ElseBB);

    Builder.SetInsertPoint(ThenBB);
    currentBasicBlock = ThenBB;
    stmt->then->accept(*this);
    if (!currentBasicBlock->getTerminator())
    {
        MergeBB = llvm::BasicBlock::Create(Context, "merge", currentFunction);
        Builder.CreateBr(MergeBB);
    }

    Builder.SetInsertPoint(ElseBB);
    currentBasicBlock = ElseBB;
    if (stmt->otherwise)
        stmt->otherwise->accept(*this);
    if (!currentBasicBlock->getTerminator())
    {
        if (!MergeBB)
            MergeBB = llvm::BasicBlock::Create(Context, "merge", currentFunction);
        Builder.CreateBr(MergeBB);
    }

    if (MergeBB)
    {
        Builder.SetInsertPoint(MergeBB);
        currentBasicBlock = MergeBB;
    }
}

void
CodeGenerator::visit(AST::WhileStmt *stmt)
{
    llvm::BasicBlock *CondBB = llvm::BasicBlock::Create(Context, "cond", currentFunction);
    llvm::BasicBlock *LoopBB = llvm::BasicBlock::Create(Context, "loop", currentFunction);
    llvm::BasicBlock *PostBB = llvm::BasicBlock::Create(Context, "post", currentFunction);

    // Need to enter the CondBB from the predecessor basic block (LLVM fallthrough is explicit!)
    Builder.CreateBr(CondBB);
    Builder.SetInsertPoint(CondBB);
    currentBasicBlock = CondBB;

    stmt->cond->accept(*this);
    llvm::Value *Cond = V;

    llvm::Value *NeqZero = Builder.CreateFCmpONE(Cond, llvm::ConstantFP::get(Context, llvm::APFloat(0.0)));
    Builder.CreateCondBr(NeqZero, LoopBB, PostBB);

    Builder.SetInsertPoint(LoopBB);
    currentBasicBlock = LoopBB;
    stmt->loop->accept(*this);
    if (!currentBasicBlock->getTerminator())
        Builder.CreateBr(CondBB);

    Builder.SetInsertPoint(PostBB);
    currentBasicBlock = PostBB;
}

void
CodeGenerator::visit(AST::ReturnStmt *stmt)
{
    stmt->expr->accept(*this);
    llvm::Value *ReturnValue = V;
    if (!ReturnValue)
        return;

    if (!currentBasicBlock->getTerminator())
        Builder.CreateRet(ReturnValue);
    else
        mi->error("attempted to insert `ret` at already terminated block");

}

void
CodeGenerator::visit(AST::IOStmt *stmt)
{
    std::string VarName = stmt->ident;

    llvm::Value *Local = Locals[VarName];

    std::vector<llvm::Value *> IdxList(2, llvm::ConstantInt::get(llvm::Type::getInt32Ty(Context), 0));

    switch (stmt->op)
    {
        case AST::Operator::INPUT:
        {
            llvm::Value *InputRef;

            if (!Local)
            {
                llvm::AllocaInst *Alloca = EmitEntryBlockAlloca(VarName);
                Locals[VarName] = Alloca;
                InputRef = Alloca;
            }
            else
                InputRef = Local;

            llvm::Value *InputGEP = Builder.CreateGEP(InputFmt, IdxList);

            std::vector<llvm::Value *> ScanfArgs {InputGEP, InputRef};
            Builder.CreateCall(Scanf, ScanfArgs);

            break;
        }
        case AST::Operator::OUTPUT:
        {
            if (!Local)
            {
                mi->error("unknown variable: " + VarName);
                return;
            }

            llvm::Value *OutputGEP = Builder.CreateGEP(OutputFmt, IdxList);
            llvm::Value *OutputVal = Builder.CreateLoad(Local, VarName);
            std::vector<llvm::Value *> PrintfArgs {OutputGEP, OutputVal};
            Builder.CreateCall(Printf, PrintfArgs);

            break;
        }
        default:
            return;
    }
}

void
CodeGenerator::visit(AST::Expr *expr)
{
    ;
}

void
CodeGenerator::visit(AST::ExprBinOp *expr)
{
    expr->lhs->accept(*this);
    llvm::Value *Left = V;
    if (!Left)
        return;

    expr->rhs->accept(*this);
    llvm::Value *Right = V;
    if (!Right)
        return;

    switch (expr->op)
    {
        case AST::Operator::PLUS:
            V = Builder.CreateFAdd(Left, Right);
            break;
        case AST::Operator::MINUS:
            V = Builder.CreateFSub(Left, Right);
            break;
        case AST::Operator::TIMES:
            V = Builder.CreateFMul(Left, Right);
            break;
        case AST::Operator::DIV:
            V = Builder.CreateFDiv(Left, Right);
            break;
        default:
            return;
    }
}

void
CodeGenerator::visit(AST::ExprIdent *expr)
{
    std::string VarName = expr->ident;

    llvm::Value *Local = Locals[VarName];

    if (!Local)
    {
        mi->error("unknown variable: " + VarName);
        return;
    }

    V = Builder.CreateLoad(Local, VarName);
}

void
CodeGenerator::visit(AST::ExprNumber *expr)
{
    V = llvm::ConstantFP::get(Context, llvm::APFloat(expr->number));
}

void
CodeGenerator::visit(AST::ExprFuncCall *expr)
{
    std::string FuncName = expr->ident;

    llvm::Function *Func = Module->getFunction(FuncName);
    if (!Func)
    {
        mi->error("unknown function: " + FuncName);
        V = nullptr;
        return;
    }

    size_t argsExpected = Func->arg_size();
    size_t argsGiven = expr->args->exprs.size();
    if (argsExpected != argsGiven)
    {
        std::stringstream ss;

        ss << "too " << (argsExpected > argsGiven ? "few" : "many") << " arguments passed to " << FuncName
            << ", expected " << argsExpected << ", have " << argsGiven;

        mi->error(ss.str());
        V = nullptr;
        return;
    }

    std::vector<llvm::Value *> Args;

    for (auto& e : expr->args->exprs)
    {
        e->accept(*this);

        if (!V)
            return;

        Args.push_back(V);
    }

    V = Builder.CreateCall(Func, Args);
}

void
CodeGenerator::visit(AST::Cond *cond)
{
    ;
}

void
CodeGenerator::visit(AST::CondUnOp *cond)
{
    cond->accept(*this);
    llvm::Value *Operand = V;
    if (!Operand)
        return;

    llvm::Value *OperandInt = Builder.CreateFPToUI(Operand, llvm::Type::getInt1Ty(Context));
    llvm::Value *UIResult = nullptr;

    switch (cond->op)
    {
        case AST::Operator::NOT:
            UIResult = Builder.CreateSub(llvm::ConstantInt::get(Context, llvm::APInt(1, 1)), OperandInt,
                    "not");
            break;
        default:
            return;
    }

    V = Builder.CreateUIToFP(UIResult, llvm::Type::getDoubleTy(Context));
}

void
CodeGenerator::visit(AST::CondBinOp *cond)
{
    cond->lhs->accept(*this);
    llvm::Value *Left = V;
    if (!Left)
        return;

    cond->rhs->accept(*this);
    llvm::Value *Right = V;
    if (!Right)
        return;

    llvm::Value *LeftInt = Builder.CreateFPToUI(Left, llvm::Type::getInt1Ty(Context));
    llvm::Value *RightInt = Builder.CreateFPToUI(Right, llvm::Type::getInt1Ty(Context));
    llvm::Value *UIResult = nullptr;

    switch (cond->op)
    {
        case AST::Operator::AND:
            UIResult = Builder.CreateAnd(LeftInt, RightInt);
            break;
        case AST::Operator::OR:
            UIResult = Builder.CreateOr(LeftInt, RightInt);
            break;
        default:
            return;
    }

    V = Builder.CreateUIToFP(UIResult, llvm::Type::getDoubleTy(Context));
}

void
CodeGenerator::visit(AST::CondCompOp *cond)
{
    cond->lhs->accept(*this);
    llvm::Value *Left = V;
    if (!Left)
        return;

    cond->rhs->accept(*this);
    llvm::Value *Right = V;
    if (!Right)
        return;

    llvm::Value *UIResult = nullptr;

    switch (cond->op)
    {
        case AST::Operator::LT:
            UIResult = Builder.CreateFCmpOLT(Left, Right);
            break;
        case AST::Operator::LTEQ:
            UIResult = Builder.CreateFCmpOLE(Left, Right);
            break;
        case AST::Operator::EQ:
            UIResult = Builder.CreateFCmpOEQ(Left, Right);
            break;
        case AST::Operator::GTEQ:
            UIResult = Builder.CreateFCmpOGE(Left, Right);
            break;
        case AST::Operator::GT:
            UIResult = Builder.CreateFCmpOGT(Left, Right);
            break;
        default:
            return;
    }

    V = Builder.CreateUIToFP(UIResult, llvm::Type::getDoubleTy(Context));
}

} // end namespace explain
