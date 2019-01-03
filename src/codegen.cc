#include <iostream>

#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/Transforms/Utils.h>

#include "ast.hh"
#include "codegen.hh"

namespace explain {

namespace CodeGen {

void
Context::initialize()
{
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    llvm::TargetMachine *TM = llvm::EngineBuilder().selectTarget();

    TheModule = std::make_unique<llvm::Module>("explain", TheContext);
    TheModule->setDataLayout(TM->createDataLayout());

    TheFPM = std::make_unique<llvm::legacy::FunctionPassManager>(TheModule.get());

    // Promote allocas to registers (mem2reg).
    TheFPM->add(llvm::createPromoteMemoryToRegisterPass());
    // Peephole optimizations and bit-twiddling optzns. (Cool abbreviation, huh?)
    TheFPM->add(llvm::createInstructionCombiningPass());
    // Reassociate expressions.
    TheFPM->add(llvm::createReassociatePass());
    // Eliminate common subexpressions.
    TheFPM->add(llvm::createGVNPass());
    // Simplify control flow graph (delete unreachable blocks, etc).
    TheFPM->add(llvm::createCFGSimplificationPass());

    TheFPM->doInitialization();
}

void
Context::codegen(std::unique_ptr<AST::Root> root)
{
    // Generate code for every function

    for (auto& f : root->funcDecls)
    {
        f->codegen(*this);
    }

    // Create main function and generate code for main
    // TODO Implement me!
}

llvm::Function *
Context::GetCurrentFunction()
{
    return TheModule->getFunction(ScopeName);
}

llvm::AllocaInst *
Context::EmitEntryBlockAlloca(llvm::Function *TheFunction, std::string VarName)
{
    llvm::IRBuilder<> TmpB(&TheFunction->getEntryBlock(),
            TheFunction->getEntryBlock().begin());

    return TmpB.CreateAlloca(llvm::Type::getDoubleTy(TheContext), nullptr, VarName);
}

llvm::Value *
Context::LogErrorV(std::string str) {
    std::cerr << str << std::endl;
    return nullptr;
}

} // end namespace CodeGen

llvm::Function *
AST::FuncDecl::codegen(CodeGen::Context &ctx)
{
    std::vector<std::string> ArgNames = args->idents;

    // Required for making the function type (an N-tuple of `double`s).
    std::vector<llvm::Type *> Doubles(ArgNames.size(), llvm::Type::getDoubleTy(ctx.TheContext));
    llvm::FunctionType *FT = llvm::FunctionType::get(llvm::Type::getDoubleTy(ctx.TheContext), Doubles,
            /* isVarArg = */ false);

    llvm::Function *F = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, ident, ctx.TheModule.get());

    // We need to make the context aware of the current function for which code is currently being generated.
    ctx.ScopeName = ident;

    // Set names for all arguments.
    unsigned Idx = 0;
    for (auto& Arg : F->args())
        Arg.setName(ArgNames[Idx++]);

    llvm::BasicBlock *BB = llvm::BasicBlock::Create(ctx.TheContext, "entry", F);
    ctx.Builder.SetInsertPoint(BB);

    // Set up local variables, install arguments into local scope.
    ctx.LocalVars.clear();
    for (auto& Arg : F->args())
    {
        llvm::AllocaInst *Alloca = ctx.EmitEntryBlockAlloca(F, Arg.getName());
        ctx.Builder.CreateStore(&Arg, Alloca);
        ctx.LocalVars[Arg.getName()] = Alloca;
    }

    // Generate code for the function body.
    for (auto& stmt : body->stmts)
    {
        llvm::Value *V = stmt->codegen(ctx);

        if (!V)
        {
            // Error reading body, remove this function.
            F->eraseFromParent();
            return nullptr;
        }
    }

    llvm::verifyFunction(*F);
    ctx.TheFPM->run(*F);
    return F;
}

llvm::Value *
AST::AssignmentStmt::codegen(CodeGen::Context &ctx)
{
    llvm::Function *F = ctx.GetCurrentFunction();
    if (!F)
        return ctx.LogErrorV("fatal error: lost scope");

    llvm::Value *Value = expr->codegen(ctx);
    if (!Value)
        return nullptr;

    llvm::Value *Variable = ctx.LocalVars[ident];

    if (!Variable)
    {
        // No AllocaInst exists in the corrent scope for the given identifier, so this is a first time assignment.
        llvm::AllocaInst *Alloca = ctx.EmitEntryBlockAlloca(F, ident);
        ctx.Builder.CreateStore(Value, Alloca);

        // Remember this binding.
        ctx.LocalVars[ident] = Alloca;
    }
    else
    {
        ctx.Builder.CreateStore(Value, Variable);
    }

    // Return value is never used since assignment in XPLN is a statement (and not an expression).
    return Value;
}

llvm::Value *
AST::IfStmt::codegen(CodeGen::Context &ctx)
{
    llvm::Value *CondV = cond->codegen(ctx);
    if (!CondV)
        return nullptr;

    // Convert condition to a boolean value by compering non-equality to 0.0.
    llvm::Value *BoolV = ctx.Builder.CreateFCmpONE(CondV,
        llvm::ConstantFP::get(ctx.TheContext, llvm::APFloat(0.0)), "ifcond");

    // TODO May need to replace this with ctx.Builder.GetInsertBlock()->getParent();
    llvm::Function *F = ctx.GetCurrentFunction();

    llvm::BasicBlock *ThenBB = llvm::BasicBlock::Create(ctx.TheContext, "then", F);
    llvm::BasicBlock *ElseBB = llvm::BasicBlock::Create(ctx.TheContext, "else", F);
    llvm::BasicBlock *MergeBB = llvm::BasicBlock::Create(ctx.TheContext, "merge", F);

    ctx.Builder.CreateCondBr(BoolV, ThenBB, ElseBB);

    // Emit code for the "then" block.
    ctx.Builder.SetInsertPoint(ThenBB);
    for (auto& Stmt : then->stmts)
    {
        llvm::Value *V =  Stmt->codegen(ctx);
        if (!V)
            return nullptr;
    }
    ctx.Builder.CreateBr(MergeBB);

    // Codegen of "then" can change the current block, update ThenBB for further insertions (???)
    ThenBB = ctx.Builder.GetInsertBlock();

    // Emit code for the "else" block.
    F->getBasicBlockList().push_back(ElseBB);
    ctx.Builder.SetInsertPoint(ElseBB);
    if (otherwise)
    {
        for (auto& Stmt : otherwise->stmts)
        {
            llvm::Value *V =  Stmt->codegen(ctx);
            if (!V)
                return nullptr;
        }
    }
    ctx.Builder.CreateBr(MergeBB);

    // Reorient the IRBuilder to the "merge" point, where subsequent instructions will be emitted to.
    F->getBasicBlockList().push_back(MergeBB);
    ctx.Builder.SetInsertPoint(MergeBB);

    // It is appropriate for the IfStmt to return the `Value *` of the AST::Cond node, since it is guaranteed not to be
    // null at this point.
    return CondV;
}

llvm::Value *
AST::WhileStmt::codegen(CodeGen::Context &ctx)
{
    llvm::Function *F = ctx.GetCurrentFunction();

    llvm::BasicBlock *PreLoopBB = llvm::BasicBlock::Create(ctx.TheContext, "preloop", F);
    llvm::BasicBlock *LoopBB = llvm::BasicBlock::Create(ctx.TheContext, "loop", F);
    llvm::BasicBlock *PostLoopBB = llvm::BasicBlock::Create(ctx.TheContext, "postloop", F);

    // Emit code for "preloop".
    ctx.Builder.SetInsertPoint(PreLoopBB);
    llvm::Value *CondV = cond->codegen(ctx);

    if (!CondV)
        return nullptr;

    llvm::Value *BoolV = ctx.Builder.CreateFCmpONE(CondV, llvm::ConstantFP::get(ctx.TheContext, llvm::APFloat(0.0)),
                                                   "loopcond");
    ctx.Builder.CreateCondBr(BoolV, LoopBB, PostLoopBB);

    // Emit code for "loop".
    F->getBasicBlockList().push_back(LoopBB);
    ctx.Builder.SetInsertPoint(LoopBB);

    if (!loop)
        return nullptr;

    for (auto& Stmt : loop->stmts)
    {
        llvm::Value *V = Stmt->codegen(ctx);
        if (!V)
            return nullptr;
    }
    ctx.Builder.CreateBr(PreLoopBB);

    // TODO ???
    PreLoopBB = ctx.Builder.GetInsertBlock();

    // Reorient the IRBuilder to the "merge" point, where subsequent instructions will be emitted to.
    F->getBasicBlockList().push_back(PostLoopBB);
    ctx.Builder.SetInsertPoint(PostLoopBB);

    // It is appropriate for the WhileStmt to return the `Value *` of the AST::Cond node, since it is guaranteed not to
    // be null at this point.
    return CondV;
}

llvm::Value *
AST::ReturnStmt::codegen(CodeGen::Context &ctx)
{
    llvm::Value *V = expr->codegen(ctx);
    if (!V)
        return nullptr;

    ctx.Builder.CreateRet(V);
    return V;
}

llvm::Value *
AST::IOStmt::codegen(CodeGen::Context &ctx)
{
    return nullptr;
}

llvm::Value *
AST::ExprBinOp::codegen(CodeGen::Context& ctx)
{
    llvm::Value *L = lhs->codegen(ctx);
    llvm::Value *R = rhs->codegen(ctx);

    if (!L || !R)
        return nullptr;

    switch (op)
    {
        case Operator::PLUS:
            return ctx.Builder.CreateFAdd(L, R, "addtmp");
        case Operator::MINUS:
            return ctx.Builder.CreateFAdd(L, R, "subtmp");
        case Operator::TIMES:
            return ctx.Builder.CreateFMul(L, R, "multmp");
        case Operator::DIV:
            return ctx.Builder.CreateFDiv(L, R, "divtmp");
        default:
            return ctx.LogErrorV("invalid binary operator");
    }
}

llvm::Value *
AST::ExprIdent::codegen(CodeGen::Context& ctx)
{
    // Perform a lookup in the local variable scope, and then emit an LLVM `load` instruction for the matching `alloca`
    // instruction (if it exists).
    llvm::Value *V = ctx.LocalVars[ident];

    if (!V)
        ctx.LogErrorV("unknown variable referenced");

    return ctx.Builder.CreateLoad(V, ident.c_str());
}

llvm::Value *
AST::ExprNumber::codegen(CodeGen::Context& ctx)
{
    return llvm::ConstantFP::get(ctx.TheContext, llvm::APFloat(number));
}

llvm::Value *
AST::ExprFuncCall::codegen(CodeGen::Context& ctx)
{
    // Look up the name in the global module table
    llvm::Function *CalleeF = ctx.TheModule->getFunction(ident);

    if (!CalleeF)
        return ctx.LogErrorV("unknown function referenced");

    if (CalleeF->arg_size() != args->exprs.size())
        return ctx.LogErrorV("incorrect # of arguments passed");

    std::vector<llvm::Value *> ArgsV;

    for (auto& e : args->exprs)
    {
        ArgsV.push_back(e->codegen(ctx));

        if (!ArgsV.back())
            return nullptr;
    }

    return ctx.Builder.CreateCall(CalleeF, ArgsV, "calltmp");
}

llvm::Value *
AST::CondUnOp::codegen(CodeGen::Context &ctx)
{
    llvm::Value *V = cond->codegen(ctx);

    if (!V)
        return nullptr;

    llvm::Value *VInt = ctx.Builder.CreateFPToUI(V, llvm::Type::getInt1Ty(ctx.TheContext), "uitmp");

    llvm::Value *Result = nullptr;

    switch (op)
    {
        case Operator::NOT:
            Result = ctx.Builder.CreateSub(llvm::ConstantInt::get(ctx.TheContext, llvm::APInt(1, 1)), VInt);
            break;
        default:
            return ctx.LogErrorV("invalid unary operator");
    }

    return ctx.Builder.CreateUIToFP(Result, llvm::Type::getDoubleTy(ctx.TheContext), "fptmp");
}

llvm::Value *
AST::CondBinOp::codegen(CodeGen::Context &ctx)
{
    llvm::Value *L = lhs->codegen(ctx);
    llvm::Value *R = rhs->codegen(ctx);

    if (!L || !R)
        return nullptr;

    llvm::Value *LInt = ctx.Builder.CreateFPToUI(L, llvm::Type::getInt1Ty(ctx.TheContext), "uitmp");
    llvm::Value *RInt = ctx.Builder.CreateFPToUI(R, llvm::Type::getInt1Ty(ctx.TheContext), "uitmp");

    llvm::Value *Result = nullptr;

    switch (op)
    {
        case Operator::AND:
            Result = ctx.Builder.CreateAnd(LInt, RInt);
            break;
        case Operator::OR:
            Result = ctx.Builder.CreateOr(LInt, RInt);
            break;
        default:
            return ctx.LogErrorV("invalid binary operator");
    }

    return ctx.Builder.CreateUIToFP(Result, llvm::Type::getDoubleTy(ctx.TheContext), "fptmp");
}

llvm::Value *
AST::CondCompOp::codegen(CodeGen::Context &ctx)
{
    llvm::Value *L = lhs->codegen(ctx);
    llvm::Value *R = rhs->codegen(ctx);

    if (!L || !R)
        return nullptr;

    llvm::Value *Result = nullptr;

    switch (op)
    {
        case Operator::LT:
            Result = ctx.Builder.CreateFCmpOLT(L, R);
            break;
        case Operator::LTEQ:
            Result = ctx.Builder.CreateFCmpOLE(L, R);
            break;
        case Operator::EQ:
            Result = ctx.Builder.CreateFCmpOEQ(L, R);
            break;
        case Operator::GTEQ:
            Result = ctx.Builder.CreateFCmpOGE(L, R);
            break;
        case Operator::GT:
            Result = ctx.Builder.CreateFCmpOGT(L, R);
            break;
        default:
            return ctx.LogErrorV("invalid binary operator");
    }

    return ctx.Builder.CreateUIToFP(Result, llvm::Type::getDoubleTy(ctx.TheContext), "fptmp");
}

} // end namespace explain
