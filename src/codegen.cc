#include <iostream>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>

#include "ast.hh"
#include "codegen.hh"

namespace explain {
namespace CodeGen {

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

llvm::Value *
Context::LogErrorV(std::string str) {
    std::cerr << str << std::endl;
    return nullptr;
}

} // end namespace CodeGen

llvm::Function *
AST::FuncDecl::codegen(CodeGen::Context &ctx)
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
    // TODO We need to solve this!
    llvm::Value *V = ctx.LocalVars[ident];

    if (!V)
        ctx.LogErrorV("unknown variable referenced");

    return V;
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
