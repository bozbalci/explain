#ifndef EXPLAIN_FORMALPARAMETERLIST_H
#define EXPLAIN_FORMALPARAMETERLIST_H

#include <string>

#include <llvm/IR/Value.h>

#include "../ASTNode.h"

namespace explain {

class FormalParameterList : public ASTNode
{
    IdentifierList formalParams;
public:
    FormalParameterList();
    ~FormalParameterList() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;

    void addParameter(Identifier *);
};

}

#endif //EXPLAIN_FORMALPARAMETERLIST_H
