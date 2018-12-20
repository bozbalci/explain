#ifndef EXPLAIN_CONDITIONALUNARYOP_H
#define EXPLAIN_CONDITIONALUNARYOP_H

#include "Conditional.h"

namespace explain {

class ConditionalUnaryOp : public Conditional
{
    Operator op;
    Conditional *cond;
public:
    ConditionalUnaryOp(Operator, Conditional *);
    ~ConditionalUnaryOp() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_CONDITIONALUNARYOP_H
