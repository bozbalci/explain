#ifndef EXPLAIN_BLOCKSTATEMENT_H
#define EXPLAIN_BLOCKSTATEMENT_H

#include <vector>
#include <string>

#include <llvm/IR/Value.h>

#include "../../Visitor/Visitor.h"
#include "../ASTNode.h"
#include "Statement.h"

namespace explain {


class BlockStatement : public ASTNode
{
    StatementList stmts;
public:
    BlockStatement();
    ~BlockStatement() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;

    void createStatement(Statement *);
};

}

#endif //EXPLAIN_BLOCKSTATEMENT_H
