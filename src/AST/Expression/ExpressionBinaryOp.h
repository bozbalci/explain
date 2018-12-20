#ifndef EXPLAIN_EXPRESSIONBINARYOP_H
#define EXPLAIN_EXPRESSIONBINARYOP_H

#include "Expression.h"

namespace explain {

class ExpressionBinaryOp : public Expression
{
    Operator op;
    Expression *lhs;
    Expression *rhs;
public:
    ExpressionBinaryOp(Operator, Expression *, Expression *);
    ~ExpressionBinaryOp() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_EXPRESSIONBINARYOP_H
