#ifndef EXPLAIN_EXPRESSIONIDENTIFIER_H
#define EXPLAIN_EXPRESSIONIDENTIFIER_H

#include <string>

#include <llvm/IR/Value.h>

#include "Expression.h"
#include "../Identifier/Identifier.h"
#include "../../Visitor/Visitor.h"

namespace explain {

class ExpressionIdentifier : public Expression
{
    Identifier *ident;
public:
    explicit ExpressionIdentifier(Identifier *);
    ~ExpressionIdentifier() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_EXPRESSIONIDENTIFIER_H
