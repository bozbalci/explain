#ifndef EXPLAIN_CONDITIONALUNARYOP_H
#define EXPLAIN_CONDITIONALUNARYOP_H

#include <string>

#include <llvm/IR/Value.h>

#include "../../Visitor/Visitor.h"
#include "../Misc/Operator.h"
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
