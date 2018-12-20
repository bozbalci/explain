#ifndef EXPLAIN_CONDITIONALCOMPOP_H
#define EXPLAIN_CONDITIONALCOMPOP_H

#include <string>

#include <llvm/IR/Value.h>

#include "../../Visitor/Visitor.h"
#include "../Misc/Operator.h"
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

#endif //EXPLAIN_CONDITIONALCOMPOP_H
