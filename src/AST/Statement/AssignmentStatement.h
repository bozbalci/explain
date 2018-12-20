#ifndef EXPLAIN_ASSIGNMENTSTATEMENT_H
#define EXPLAIN_ASSIGNMENTSTATEMENT_H

#include "Statement.h"

namespace explain {

class AssignmentStatement : public Statement
{
    Identifier *lhs;
    Expression *rhs;
public:
    AssignmentStatement(Identifier *, Expression *);
    ~AssignmentStatement() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_ASSIGNMENTSTATEMENT_H
