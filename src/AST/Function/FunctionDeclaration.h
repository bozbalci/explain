#ifndef EXPLAIN_FUNCTIONDECLARATION_H
#define EXPLAIN_FUNCTIONDECLARATION_H

#include "../ASTNode.h"
#include "../Entry.h"

namespace explain {

class FunctionDeclaration : public Entry
{
    Identifier *ident;
    IdentifierList formalArgs;
    BlockStatement *body;
public:
    FunctionDeclaration(Identifier *, IdentifierList, BlockStatement *);
    ~FunctionDeclaration() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_FUNCTIONDECLARATION_H
