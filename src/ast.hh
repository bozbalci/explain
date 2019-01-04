#ifndef EXPLAIN_AST_HH
#define EXPLAIN_AST_HH

#include <iostream>
#include <vector>
#include <memory>
#include <utility>

namespace explain {

namespace AST {

class Node;
class Root;
class BlockStmt;
class FuncDeclArgs;
class FuncCallArgs;
class Entry;
class Stmt;
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

class Consumer
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

enum class NodeType
{
    ROOT,
    BLOCK_STMT,
    FUNC_DECL_ARGS,
    FUNC_CALL_ARGS,
    ENTRY,
    STMT,
    FUNC_DECL,
    ASSIGNMENT_STMT,
    IF_STMT,
    WHILE_STMT,
    RETURN_STMT,
    IO_STMT,
    EXPR,
    EXPR_BIN_OP,
    EXPR_IDENT,
    EXPR_NUMBER,
    EXPR_FUNC_CALL,
    COND,
    COND_UN_OP,
    COND_BIN_OP,
    COND_COMP_OP
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

/// Base class for all Abstract Syntax Tree (AST) classes.
class Node
{
public:
    Node() = default;
    virtual ~Node() = default;
    virtual void accept(Consumer&) = 0;
    virtual NodeType getNodeType() = 0;
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
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::ROOT; }
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
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::BLOCK_STMT; }
};

class FuncDeclArgs : public Node
{
public:
    std::vector<std::string> idents;

    FuncDeclArgs() = default;
    explicit FuncDeclArgs(std::vector<std::string> idents)
        : idents(std::move(idents)) {}
    ~FuncDeclArgs() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::FUNC_DECL_ARGS; }
};

class FuncCallArgs : public Node
{
public:
    std::vector<std::unique_ptr<Expr>> exprs;

    FuncCallArgs() = default;
    explicit FuncCallArgs(std::vector<std::unique_ptr<Expr>> exprs)
        : exprs(std::move(exprs)) {}
    ~FuncCallArgs() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::FUNC_CALL_ARGS; }
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
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::ENTRY; }
};


class Stmt : public Entry
{
public:
    Stmt() = default;
    ~Stmt() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::STMT; }
};

class FuncDecl : public Entry
{
public:
    std::string ident;
    std::unique_ptr<FuncDeclArgs> args;
    std::unique_ptr<BlockStmt> body;

    bool isXplnEntry;

    FuncDecl(std::string ident, std::unique_ptr<FuncDeclArgs> args, std::unique_ptr<BlockStmt> body)
            : ident(std::move(ident)), args(std::move(args)), body(std::move(body)), isXplnEntry(false) {}
    ~FuncDecl() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::FUNC_DECL; }
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
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::ASSIGNMENT_STMT; }
};

class IfStmt : public Stmt
{
public:
    std::unique_ptr<Cond> cond;
    std::unique_ptr<BlockStmt> then, otherwise;

    IfStmt(std::unique_ptr<Cond> cond, std::unique_ptr<BlockStmt> then, std::unique_ptr<BlockStmt> otherwise)
            : cond(std::move(cond)), then(std::move(then)), otherwise(std::move(otherwise)) {}
    ~IfStmt() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::IF_STMT; }
};

class WhileStmt : public Stmt
{
public:
    std::unique_ptr<Cond> cond;
    std::unique_ptr<BlockStmt> loop;

    WhileStmt(std::unique_ptr<Cond> cond, std::unique_ptr<BlockStmt> loop)
            : cond(std::move(cond)), loop(std::move(loop)) {}
    ~WhileStmt() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::WHILE_STMT; }
};

class ReturnStmt : public Stmt
{
public:
    std::unique_ptr<Expr> expr;

    explicit ReturnStmt(std::unique_ptr<Expr> expr)
            : expr(std::move(expr)) {}
    ~ReturnStmt() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::RETURN_STMT; }
};

class IOStmt : public Stmt
{
public:
    Operator op;
    std::string ident;

    IOStmt(Operator op, std::string ident)
            : op(op), ident(std::move(ident)) {}
    ~IOStmt() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::IO_STMT; }
};

//===--------------------------------------------------------------------------------===//
// Expression nodes
//===--------------------------------------------------------------------------------===//

class Expr : public Node
{
public:
    Expr() = default;
    ~Expr() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::EXPR; }
};

class ExprBinOp : public Expr
{
public:
    Operator op;
    std::unique_ptr<Expr> lhs, rhs;

    ExprBinOp(Operator op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs)
        : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}
    ~ExprBinOp() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::EXPR_BIN_OP; }
};

class ExprIdent : public Expr
{
public:
    std::string ident;

    explicit ExprIdent(std::string ident)
        : ident(std::move(ident)) {}
    ~ExprIdent() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::EXPR_IDENT; }
};

class ExprNumber : public Expr
{
public:
    double number;

    explicit ExprNumber(double number)
        : number(number) {}
    ~ExprNumber() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::EXPR_NUMBER; }
};

class ExprFuncCall : public Expr
{
public:
    std::string ident;
    std::unique_ptr<FuncCallArgs> args;

    ExprFuncCall(std::string ident, std::unique_ptr<FuncCallArgs> args)
        : ident(std::move(ident)), args(std::move(args)) {}
    ~ExprFuncCall() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::EXPR_FUNC_CALL; }
};

//===--------------------------------------------------------------------------------===//
// Conditional nodes
//===--------------------------------------------------------------------------------===//

class Cond : public Node
{
public:
    Cond() = default;
    ~Cond() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::COND; }
};

class CondUnOp : public Cond
{
public:
    Operator op;
    std::unique_ptr<Cond> cond;

    CondUnOp(Operator op, std::unique_ptr<Cond> cond)
        : op(op), cond(std::move(cond)) {}
    ~CondUnOp() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::COND_UN_OP; }
};

class CondBinOp : public Cond
{
public:
    Operator op;
    std::unique_ptr<Cond> lhs, rhs;

    CondBinOp(Operator op, std::unique_ptr<Cond> lhs, std::unique_ptr<Cond> rhs)
        : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}
    ~CondBinOp() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::COND_BIN_OP; }
};

class CondCompOp : public Cond
{
public:
    Operator op;
    std::unique_ptr<Expr> lhs, rhs;

    CondCompOp(Operator op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs)
        : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}
    ~CondCompOp() override = default;
    void accept(Consumer& v) override { v.visit(this); }
    NodeType getNodeType() override { return NodeType::COND_COMP_OP; }
};

} // end namespace AST

} // end namespace explain

#endif //EXPLAIN_AST_HH
