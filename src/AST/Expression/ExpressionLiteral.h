#ifndef EXPLAIN_EXPRESSIONLITERAL_H
#define EXPLAIN_EXPRESSIONLITERAL_H

#include <string>

#include <llvm/IR/Value.h>

#include "Expression.h"
#include "../../Visitor/Visitor.h"

namespace explain {

class ExpressionLiteral : public Expression
{
    double value;
public:
    explicit ExpressionLiteral(double);
    ~ExpressionLiteral() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_EXPRESSIONLITERAL_H
