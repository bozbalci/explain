#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>

#include "ast.hh"

namespace explain {

namespace CodeGen {

static llvm::LLVMContext TheContext;
static llvm::IRBuilder<> Builder(TheContext);
static std::unique_ptr<llvm::Module> TheModule;
static std::map<std::string, llvm::Value *> NamedValues;

} // namespace explain::CodeGen

llvm::Value *
AST::ExprBinOp::codegen()
{
    return nullptr;
}

llvm::Value *
AST::ExprIdent::codegen()
{
    return nullptr;
}

llvm::Value *
AST::ExprNumber::codegen()
{
    return nullptr;
}

llvm::Value *
AST::ExprFuncCall::codegen()
{
    return nullptr;
}

} // namespace explain
