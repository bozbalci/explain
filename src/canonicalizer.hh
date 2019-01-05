#ifndef EXPLAIN_CANONICALIZER_HH
#define EXPLAIN_CANONICALIZER_HH

#include <string>

#include "ast.hh"
#include "messages.hh"

namespace explain {

/// The AST Canonicalization Phase is a set of transformations and verifications performed against the Abstract Syntax
/// Tree. After this phase has been completed, the compiler will be in either of the following states:
///
///     a.) the AST is guaranteed to be in canonical form, where code generation can begin
///     b.) the compiler reports an error (the AST was malformed before canonicalization)
///
/// The AST is said to be in canonical form when all of the following have been established:
///
///    1.) Every AST node except for ones which are optional (e.g. `else` block of an if-then-else) holds a non-null
///        pointer value.
///    2.) Every usage of the identifier "xpln-main" inside function declarations and function calls is mangled.
///    3.) A `FuncDecl` node for the top-level statements have been created and inserted to the root node.
///    4.) Every `FuncDecl` node has at least one `ReturnStmt` within their body.
///    5.) Every node following a `ReturnStmt` inside `BlockStmt` nodes is pruned.
///    6.) Every node with an Operator field holds a valid operator for their purposes.
///
class Canonicalizer : public AST::Consumer
{
    MessageIssuer *mi;

    std::string mangledMain = "xpln-mangled-main";
    bool encounteredReturnStmt;
public:
    explicit Canonicalizer(MessageIssuer *mi)
        : mi(mi), encounteredReturnStmt(false) {}

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

#endif //EXPLAIN_CANONICALIZER_HH
