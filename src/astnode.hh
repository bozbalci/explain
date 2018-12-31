#ifndef ASTNODE_HH
#define ASTNODE_HH

#include <iostream>
#include <list>
#include <utility>

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

class Node
{
public:
    Node() = default;

    virtual void print(int level) {
        Node::indent(level);
        std::cout << "Node" << std::endl;
    }

    static void indent(int level) {
        std::cout << std::string(level * 2, ' ');
    }
};

class Entry : public Node
{
public:
    Entry() = default;
    void print(int level) override;
};

class Root : public Node
{
public:
    std::list<Entry *> entries;

    Root() = default;
    void print(int level) override;
};

class Stmt : public Entry
{
public:
    Stmt() = default;
    void print(int level) override;
};

class BlockStmt : public Node
{
public:
    std::list<Stmt *> stmts;

    BlockStmt() = default;
    void print(int level) override;
};

class FuncDecl : public Entry
{
public:
    std::string ident;
    FuncDeclArgs *args;
    BlockStmt *body;

    FuncDecl(std::string ident, FuncDeclArgs *args, BlockStmt *body)
        : ident(ident), args(args), body(body) {}
    void print(int level) override;
};

class AssignmentStmt : public Stmt
{
public:
    std::string ident;
    Expr *expr;

    AssignmentStmt(std::string ident, Expr *expr)
        : ident(ident), expr(expr) {}
    void print(int level) override;
};

class IfStmt : public Stmt
{
public:
    Cond *cond;
    BlockStmt *then, *otherwise;

    IfStmt(Cond *cond, BlockStmt *then, BlockStmt *otherwise)
        : cond(cond), then(then), otherwise(otherwise) {}
    void print(int level) override;
};

class WhileStmt : public Stmt
{
public:
    Cond *cond;
    BlockStmt *loop;

    WhileStmt(Cond *cond, BlockStmt *loop)
        : cond(cond), loop(loop) {}
    void print(int level) override;
};

class ReturnStmt : public Stmt
{
public:
    Expr *expr;

    ReturnStmt(Expr *expr)
        : expr(expr) {}
    void print(int level) override;
};

class IOStmt : public Stmt
{
public:
    Operator op;
    std::string ident;

    IOStmt(Operator op, std::string ident)
        : op(op), ident(ident) {}
    void print(int level) override;
};

class Expr : public Node
{
public:
    Expr() = default;
    void print(int level) override;
};

class ExprBinOp : public Expr
{
public:
    Operator op;
    Expr *lhs, *rhs;

    ExprBinOp(Operator op, Expr *lhs, Expr *rhs)
        : op(op), lhs(lhs), rhs(rhs) {}
    void print(int level) override;
};

class ExprIdent : public Expr
{
public:
    std::string ident;

    ExprIdent(std::string ident)
        : ident(ident) {}
    void print(int level) override;
};

class ExprNumber : public Expr
{
public:
    double number;

    ExprNumber(double number)
        : number(number) {}
    void print(int level) override;
};

class ExprFuncCall : public Expr
{
public:
    std::string ident;
    FuncCallArgs *args;

    ExprFuncCall(std::string ident, FuncCallArgs *args)
        : ident(ident), args(args) {}
    void print(int level) override;
};

class Cond : public Node
{
public:
    Cond() = default;
    void print(int level) override;
};

class CondUnOp : public Cond
{
public:
    Operator op;
    Cond *cond;

    CondUnOp(Operator op, Cond *cond)
        : op(op), cond(cond) {}
    void print(int level) override;
};

class CondBinOp : public Cond
{
public:
    Operator op;
    Cond *lhs, *rhs;

    CondBinOp(Operator op, Cond *lhs, Cond *rhs)
        : op(op), lhs(lhs), rhs(rhs) {}
    void print(int level) override;
};

class CondCompOp : public Cond
{
public:
    Operator op;
    Expr *lhs, *rhs;

    CondCompOp(Operator op, Expr *lhs, Expr *rhs)
        : op(op), lhs(lhs), rhs(rhs) {}
    void print(int level) override;
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
    std::list<Expr *> exprs;

    FuncCallArgs() = default;
    void print(int level) override;
};

#endif // ASTNODE_HH
