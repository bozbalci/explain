#ifndef EXPLAIN_PRINTER_HH
#define EXPLAIN_PRINTER_HH

#include <string>

#include "ast.hh"
#include "messages.hh"

namespace explain {

class PrettyPrinter : public AST::Consumer
{
    MessageIssuer *mi;

    int level;

    std::string spaces();
    void indent();
    void dedent();
    std::string operatorToString(AST::Operator op);
public:
    explicit PrettyPrinter(MessageIssuer *mi)
        : mi(mi), level(0) {}

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

#endif //EXPLAIN_PRINTER_HH
