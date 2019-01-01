#ifndef EXPLAIN_AST_HH
#define EXPLAIN_AST_HH

#include <iostream>
#include <list>
#include <memory>
#include <utility>

#include <llvm/IR/Value.h>

#include "codegen.hh"

namespace explain {
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

enum class Operator
{
    // IO operators
    INPUT,
    OUTPUT,

    // Arithmetic operators
    PLUS,
    MINUS,
    TIMES,
    DIV,

    // Logical operators
    NOT,
    AND,
    OR,

    // Comparison operators
    LT,
    LTEQ,
    EQ,
    GTEQ,
    GT
};

class Node
{
public:
    Node() = default;

    virtual void print(int level) {
        Node::indent(level);
        std::cout << "Node" << std::endl;
    }

    static void indent(int level) {
        std::cout << std::string(static_cast<unsigned long>(level * 2), ' ');
    }
};

class Entry : public Node
{
public:
    Entry() = default;
    virtual ~Entry() = default;
    void print(int level) override;
    virtual bool validAtTopLevel() = 0;
};

class Root : public Node
{
public:
    std::list<std::unique_ptr<FuncDecl>> funcDecls;
    std::list<std::unique_ptr<Stmt>> topLevelStmts;

    Root() = default;
    void print(int level) override;
};

class Stmt : public Entry
{
public:
    Stmt() = default;
    ~Stmt() override = default;
    void print(int level) override;
    bool validAtTopLevel() override;
};

class BlockStmt : public Node
{
public:
    std::list<std::unique_ptr<Stmt>> stmts;

    BlockStmt() = default;
    void print(int level) override;
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
    void print(int level) override;
    bool validAtTopLevel() override;
};

class AssignmentStmt : public Stmt
{
public:
    std::string ident;
    std::unique_ptr<Expr> expr;

    AssignmentStmt(std::string ident, std::unique_ptr<Expr> expr)
        : ident(std::move(ident)), expr(std::move(expr)) {}
    void print(int level) override;
};

class IfStmt : public Stmt
{
public:
    std::unique_ptr<Cond> cond;
    std::unique_ptr<BlockStmt> then, otherwise;

    IfStmt(std::unique_ptr<Cond> cond, std::unique_ptr<BlockStmt> then, std::unique_ptr<BlockStmt> otherwise)
        : cond(std::move(cond)), then(std::move(then)), otherwise(std::move(otherwise)) {}
    void print(int level) override;
};

class WhileStmt : public Stmt
{
public:
    std::unique_ptr<Cond> cond;
    std::unique_ptr<BlockStmt> loop;

    WhileStmt(std::unique_ptr<Cond> cond, std::unique_ptr<BlockStmt> loop)
        : cond(std::move(cond)), loop(std::move(loop)) {}
    void print(int level) override;
};

class ReturnStmt : public Stmt
{
public:
    std::unique_ptr<Expr> expr;

    explicit ReturnStmt(std::unique_ptr<Expr> expr)
        : expr(std::move(expr)) {}
    void print(int level) override;
};

class IOStmt : public Stmt
{
public:
    Operator op;
    std::string ident;

    IOStmt(Operator op, std::string ident)
        : op(op), ident(std::move(ident)) {}
    void print(int level) override;
};

class Expr : public Node
{
public:
    Expr() = default;
    virtual ~Expr() = default;
    void print(int level) override;
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
    void print(int level) override;
    llvm::Value *codegen(CodeGen::Context& ctx) override;
};

class ExprIdent : public Expr
{
public:
    std::string ident;

    explicit ExprIdent(std::string ident)
        : ident(std::move(ident)) {}
    ~ExprIdent() override = default;
    void print(int level) override;
    llvm::Value *codegen(CodeGen::Context& ctx) override;
};

class ExprNumber : public Expr
{
public:
    double number;

    explicit ExprNumber(double number)
        : number(number) {}
    ~ExprNumber() override = default;
    void print(int level) override;
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
    void print(int level) override;
    llvm::Value *codegen(CodeGen::Context& ctx) override;
};

class Cond : public Node
{
public:
    Cond() = default;
    virtual ~Cond() = default;
    void print(int level) override;
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
    void print(int level) override;
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
    void print(int level) override;
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
    void print(int level) override;
    llvm::Value *codegen(CodeGen::Context& ctx) override;
};

class FuncDeclArgs : public Node
{
public:
    std::list<std::string> idents;

    FuncDeclArgs() = default;
    void print(int level) override;
};

class FuncCallArgs : public Node
{
public:
    std::list<std::unique_ptr<Expr>> exprs;

    FuncCallArgs() = default;
    void print(int level) override;
};

}} // namespace explain::AST

#endif // EXPLAIN_AST_HH
