#ifndef EXPLAIN_IFSTATEMENT_H
#define EXPLAIN_IFSTATEMENT_H

#include "Statement.h"

namespace explain {

class IfStatement : public Statement
{
    Conditional *cond;
    BlockStatement *blockThen;
    BlockStatement *blockElse;
public:
    IfStatement(Conditional *, BlockStatement *, BlockStatement *);
    ~IfStatement() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_IFSTATEMENT_H
