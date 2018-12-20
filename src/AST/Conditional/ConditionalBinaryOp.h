#ifndef EXPLAIN_CONDITIONALBINARYOP_H
#define EXPLAIN_CONDITIONALBINARYOP_H

#include <string>

#include <llvm/IR/Value.h>

#include "../../Visitor/Visitor.h"
#include "../Misc/Operator.h"
#include "Conditional.h"

namespace explain {

class ConditionalBinaryOp : public Conditional
{
    Operator op;
    Conditional *lhs, *rhs;
public:
    ConditionalBinaryOp(Operator, Conditional *, Conditional *);
    ~ConditionalBinaryOp() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_CONDITIONALBINARYOP_H
