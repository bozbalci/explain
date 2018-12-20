#ifndef EXPLAIN_BLOCKSTATEMENT_H
#define EXPLAIN_BLOCKSTATEMENT_H

#include <vector>

#include "../ASTNode.h"

namespace explain {

using StatementList = std::vector<Statement *>;

class BlockStatement : public ASTNode
{
    StatementList stmts;
public:
    explicit BlockStatement(StatementList);
    ~BlockStatement() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_BLOCKSTATEMENT_H
