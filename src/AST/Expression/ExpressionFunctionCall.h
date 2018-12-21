#ifndef EXPLAIN_EXPRESSIONFUNCTIONCALL_H
#define EXPLAIN_EXPRESSIONFUNCTIONCALL_H

#include <vector>

#include "Expression.h"
#include "../Identifier/Identifier.h"

namespace explain {


class ExpressionFunctionCall : public Expression
{
    Identifier *functionIdent;
    ExpressionList actualParams;
public:
    ExpressionFunctionCall(Identifier *, ExpressionList);
    ~ExpressionFunctionCall() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_EXPRESSIONFUNCTIONCALL_H
