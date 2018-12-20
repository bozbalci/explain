#ifndef EXPLAIN_RETURNSTATEMENT_H
#define EXPLAIN_RETURNSTATEMENT_H

#include "Statement.h"

namespace explain {

class ReturnStatement : public Statement
{
    Expression *expr;
public:
    explicit ReturnStatement(Expression *);
    ~ReturnStatement() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_RETURNSTATEMENT_H
