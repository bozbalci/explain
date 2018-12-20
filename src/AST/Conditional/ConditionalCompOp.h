#ifndef EXPLAIN_CONDITIONALCOMPARISIONOP_H
#define EXPLAIN_CONDITIONALCOMPARISIONOP_H

#include "Conditional.h"

namespace explain {

class ConditionalCompOp : public Conditional
{
    Operator op;
    Expression *lhs, *rhs;
public:
    ConditionalCompOp(Operator, Expression *, Expression *);
    ~ConditionalCompOp() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_CONDITIONALCOMPARISIONOP_H
