#ifndef EXPLAIN_CODEGEN_HH
#define EXPLAIN_CODEGEN_HH

#include <map>
#include <memory>
#include <string>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>

#include "ast.hh"

namespace explain {

// TODO Common forward declarations of classes, is there a better solution?
namespace AST {

class Node;
class Entry;
class Root;
class Stmt;
class BlockStmt;
class FuncDecl;
class AssignmentStmt;
class IfStmt;
class WhileStmt;
class ReturnStmt;
class IOStmt;
class Expr;
class ExprBinOp;
class ExprIdent;
class ExprNumber;
class ExprFuncCall;
class Cond;
class CondUnOp;
class CondBinOp;
class CondCompOp;
class FuncDeclArgs;
class FuncCallArgs;

} // end namespace AST

namespace CodeGen {

class Context {
public:
    llvm::LLVMContext TheContext;
    llvm::IRBuilder<> Builder;
    std::unique_ptr<llvm::Module> TheModule;
    std::map<std::string, llvm::Value *> NamedValues;

    Context()
        : Builder(llvm::IRBuilder<>(TheContext)) {}


    void codegen(std::unique_ptr<AST::Root> root);

    llvm::Value *LogErrorV(std::string str);
};

} // end namespace CodeGen
} // end namespace explain

#endif //EXPLAIN_CODEGEN_HH
