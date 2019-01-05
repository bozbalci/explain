#ifndef EXPLAIN_CODEGEN_HH
#define EXPLAIN_CODEGEN_HH

#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/Transforms/Utils.h>

#include "ast.hh"
#include "messages.hh"

namespace explain {

class CodeGenerator : public AST::Consumer
{
    MessageIssuer *mi;

    llvm::LLVMContext Context;
    llvm::IRBuilder<> Builder;
    std::unique_ptr<llvm::Module> Module;
    std::unique_ptr<llvm::legacy::FunctionPassManager> FPM;

    llvm::TargetMachine *TargetMachine;

    std::map<std::string, llvm::AllocaInst *> Locals;

    // The most recently generated LLVM value
    llvm::Value *V;

    llvm::Function *currentFunction = nullptr;
    llvm::BasicBlock *currentBasicBlock = nullptr;

    llvm::GlobalVariable *InputFmt = nullptr, *OutputFmt = nullptr;
    llvm::Function *Printf = nullptr, *Scanf = nullptr;

    llvm::AllocaInst *EmitEntryBlockAlloca(const std::string& VarName);
public:
    explicit CodeGenerator(MessageIssuer *mi, const std::string& ModuleName);

    void emitObject(const std::string& Filename);
    void emitDriver(const std::string& Filename);
    void printModule(const std::string& Filename);

    void visit(AST::Root *root) override;
    void visit(AST::BlockStmt *block) override;
    void visit(AST::FuncDeclArgs *args) override;
    void visit(AST::FuncCallArgs *args) override;
    void visit(AST::Entry *entry) override;
    void visit(AST::Stmt *stmt) override;
    void visit(AST::FuncDecl *decl) override;
    void visit(AST::AssignmentStmt *stmt) override;
    void visit(AST::IfStmt *stmt) override;
    void visit(AST::WhileStmt *stmt) override;
    void visit(AST::ReturnStmt *stmt) override;
    void visit(AST::IOStmt *stmt) override;
    void visit(AST::Expr *expr) override;
    void visit(AST::ExprBinOp *expr) override;
    void visit(AST::ExprIdent *expr) override;
    void visit(AST::ExprNumber *expr) override;
    void visit(AST::ExprFuncCall *expr) override;
    void visit(AST::Cond *cond) override;
    void visit(AST::CondUnOp *cond) override;
    void visit(AST::CondBinOp *cond) override;
    void visit(AST::CondCompOp *cond) override;
};

} // end namespace explain

#endif //EXPLAIN_CODEGEN_HH
