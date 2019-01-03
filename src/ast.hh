#ifndef EXPLAIN_AST_HH
#define EXPLAIN_AST_HH

#include <iostream>
#include <vector>
#include <memory>
#include <utility>

#include <llvm/IR/Value.h>

#include "ast_decls.inc"

#include "codegen.hh"

namespace explain {

namespace CodeGen { class Context; }

namespace AST {

class Visitor
{
public:
    virtual void visit(AST::Root *root) = 0;
    virtual void visit(AST::BlockStmt *block) = 0;
    virtual void visit(AST::FuncDeclArgs *args) = 0;
    virtual void visit(AST::FuncCallArgs *args) = 0;
    virtual void visit(AST::Entry *entry) = 0;
    virtual void visit(AST::Stmt *stmt) = 0;
    virtual void visit(AST::FuncDecl *decl) = 0;
    virtual void visit(AST::AssignmentStmt *stmt) = 0;
    virtual void visit(AST::IfStmt *stmt) = 0;
    virtual void visit(AST::WhileStmt *stmt) = 0;
    virtual void visit(AST::ReturnStmt *stmt) = 0;
    virtual void visit(AST::IOStmt *stmt) = 0;
    virtual void visit(AST::Expr *expr) = 0;
    virtual void visit(AST::ExprBinOp *expr) = 0;
    virtual void visit(AST::ExprIdent *expr) = 0;
    virtual void visit(AST::ExprNumber *expr) = 0;
    virtual void visit(AST::ExprFuncCall *expr) = 0;
    virtual void visit(AST::Cond *cond) = 0;
    virtual void visit(AST::CondUnOp *cond) = 0;
    virtual void visit(AST::CondBinOp *cond) = 0;
    virtual void visit(AST::CondCompOp *cond) = 0;
};

enum class Operator
{
    INPUT,
    OUTPUT,
    PLUS,
    MINUS,
    TIMES,
    DIV,
    NOT,
    AND,
    OR,
    LT,
    LTEQ,
    EQ,
    GTEQ,
    GT
};

std::string get_op_repr(Operator);

enum class StatementType
{
    ASSIGNMENT,
    IF,
    WHILE,
    RETURN,
    IO
};

/// Base class for all Abstract Syntax Tree (AST) classes.
class Node
{
public:
    Node() = default;
    virtual ~Node() = default;
    virtual void accept(Visitor&) = 0;
};

//===--------------------------------------------------------------------------------===//
// Root node
//===--------------------------------------------------------------------------------===//

class Root : public Node
{
public:
    std::vector<std::unique_ptr<FuncDecl>> funcDecls;
    std::vector<std::unique_ptr<Stmt>> topLevelStmts;

    Root() = default;
    ~Root() override = default;
    void accept(Visitor& v) override { v.visit(this); }
};

//===--------------------------------------------------------------------------------===//
// Utility nodes
//===--------------------------------------------------------------------------------===//

class BlockStmt : public Node
{
public:
    std::vector<std::unique_ptr<Stmt>> stmts;

    BlockStmt() = default;
    explicit BlockStmt(std::vector<std::unique_ptr<Stmt>> stmts)
        : stmts(std::move(stmts)) {}
    ~BlockStmt() override = default;
    void accept(Visitor& v) override { v.visit(this); }
};

class FuncDeclArgs : public Node
{
public:
    std::vector<std::string> idents;

    FuncDeclArgs() = default;
    explicit FuncDeclArgs(std::vector<std::string> idents)
        : idents(std::move(idents)) {}
    ~FuncDeclArgs() override = default;
    void accept(Visitor& v) override { v.visit(this); }
};

class FuncCallArgs : public Node
{
public:
    std::vector<std::unique_ptr<Expr>> exprs;

    FuncCallArgs() = default;
    explicit FuncCallArgs(std::vector<std::unique_ptr<Expr>> exprs)
        : exprs(std::move(exprs)) {}
    ~FuncCallArgs() override = default;
    void accept(Visitor& v) override { v.visit(this); }
};

//===--------------------------------------------------------------------------------===//
// Top level entry nodes
//===--------------------------------------------------------------------------------===//

/// Entry is not a concrete Abstract Syntax Tree (AST) node class, it exists solely for the purpose of providing a
/// variant type class during parsing.
class Entry : public Node
{
public:
    Entry() = default;
    ~Entry() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    virtual bool validAtTopLevel() = 0;
};


class Stmt : public Entry
{
public:
    Stmt() = default;
    ~Stmt() override = default;
    void accept(Visitor& v) override { v.visit(this); }


    virtual llvm::Value *codegen(CodeGen::Context& ctx) = 0;
    bool validAtTopLevel() override;
    virtual StatementType getType() = 0;
};

class FuncDecl : public Entry
{
public:
    std::string ident;
    std::unique_ptr<FuncDeclArgs> args;
    std::unique_ptr<BlockStmt> body;

    FuncDecl(std::string ident, std::unique_ptr<FuncDeclArgs> args, std::unique_ptr<BlockStmt> body)
            : ident(std::move(ident)), args(std::move(args)), body(std::move(body)) {}
    ~FuncDecl() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Function *codegen(CodeGen::Context& ctx);
    bool validAtTopLevel() override;
};

//===--------------------------------------------------------------------------------===//
// Statement nodes
//===--------------------------------------------------------------------------------===//

class AssignmentStmt : public Stmt
{
public:
    std::string ident;
    std::unique_ptr<Expr> expr;

    AssignmentStmt(std::string ident, std::unique_ptr<Expr> expr)
            : ident(std::move(ident)), expr(std::move(expr)) {}
    ~AssignmentStmt() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
    StatementType getType() override;
};

class IfStmt : public Stmt
{
public:
    std::unique_ptr<Cond> cond;
    std::unique_ptr<BlockStmt> then, otherwise;

    IfStmt(std::unique_ptr<Cond> cond, std::unique_ptr<BlockStmt> then, std::unique_ptr<BlockStmt> otherwise)
            : cond(std::move(cond)), then(std::move(then)), otherwise(std::move(otherwise)) {}
    ~IfStmt() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
    StatementType getType() override;
};

class WhileStmt : public Stmt
{
public:
    std::unique_ptr<Cond> cond;
    std::unique_ptr<BlockStmt> loop;

    WhileStmt(std::unique_ptr<Cond> cond, std::unique_ptr<BlockStmt> loop)
            : cond(std::move(cond)), loop(std::move(loop)) {}
    ~WhileStmt() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
    StatementType getType() override;
};

class ReturnStmt : public Stmt
{
public:
    std::unique_ptr<Expr> expr;

    explicit ReturnStmt(std::unique_ptr<Expr> expr)
            : expr(std::move(expr)) {}
    ~ReturnStmt() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
    StatementType getType() override;
};

class IOStmt : public Stmt
{
public:
    Operator op;
    std::string ident;

    IOStmt(Operator op, std::string ident)
            : op(op), ident(std::move(ident)) {}
    ~IOStmt() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
    StatementType getType() override;
};

//===--------------------------------------------------------------------------------===//
// Expression nodes
//===--------------------------------------------------------------------------------===//

class Expr : public Node
{
public:
    Expr() = default;
    ~Expr() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    virtual llvm::Value *codegen(CodeGen::Context& ctx) = 0;
};

class ExprBinOp : public Expr
{
public:
    Operator op;
    std::unique_ptr<Expr> lhs, rhs;

    ExprBinOp(Operator op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs)
        : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}
    ~ExprBinOp() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
};

class ExprIdent : public Expr
{
public:
    std::string ident;

    explicit ExprIdent(std::string ident)
        : ident(std::move(ident)) {}
    ~ExprIdent() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
};

class ExprNumber : public Expr
{
public:
    double number;

    explicit ExprNumber(double number)
        : number(number) {}
    ~ExprNumber() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
};

class ExprFuncCall : public Expr
{
public:
    std::string ident;
    std::unique_ptr<FuncCallArgs> args;

    ExprFuncCall(std::string ident, std::unique_ptr<FuncCallArgs> args)
        : ident(std::move(ident)), args(std::move(args)) {}
    ~ExprFuncCall() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
};

//===--------------------------------------------------------------------------------===//
// Conditional nodes
//===--------------------------------------------------------------------------------===//

class Cond : public Node
{
public:
    Cond() = default;
    ~Cond() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    virtual llvm::Value *codegen(CodeGen::Context& ctx) = 0;
};

class CondUnOp : public Cond
{
public:
    Operator op;
    std::unique_ptr<Cond> cond;

    CondUnOp(Operator op, std::unique_ptr<Cond> cond)
        : op(op), cond(std::move(cond)) {}
    ~CondUnOp() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
};

class CondBinOp : public Cond
{
public:
    Operator op;
    std::unique_ptr<Cond> lhs, rhs;

    CondBinOp(Operator op, std::unique_ptr<Cond> lhs, std::unique_ptr<Cond> rhs)
        : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}
    ~CondBinOp() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
};

class CondCompOp : public Cond
{
public:
    Operator op;
    std::unique_ptr<Expr> lhs, rhs;

    CondCompOp(Operator op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs)
        : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}
    ~CondCompOp() override = default;
    void accept(Visitor& v) override { v.visit(this); }

    llvm::Value *codegen(CodeGen::Context& ctx) override;
};

} // end namespace AST

} // end namespace explain

#endif //EXPLAIN_AST_HH
