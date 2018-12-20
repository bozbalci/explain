#ifndef EXPLAIN_IOSTATEMENT_H
#define EXPLAIN_IOSTATEMENT_H

#include "Statement.h"

namespace explain {

class IOStatement : public Statement
{
    Operator op;
    Identifier *ident;
public:
    IOStatement(Operator, Identifier *);
    ~IOStatement() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_IOSTATEMENT_H
