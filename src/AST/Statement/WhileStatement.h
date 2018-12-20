#ifndef EXPLAIN_WHILESTATEMENT_H
#define EXPLAIN_WHILESTATEMENT_H

#include "Statement.h"

namespace explain {

class WhileStatement : public Statement
{
    Conditional *cond;
    BlockStatement *block;
public:
    WhileStatement(Conditional *, BlockStatement *);
    ~WhileStatement() override;

    llvm::Value *generateCode() override;
    std::string toString() override;

    void accept(Visitor&) override;
};

}

#endif //EXPLAIN_WHILESTATEMENT_H
