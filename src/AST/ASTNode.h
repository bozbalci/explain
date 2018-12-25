#ifndef EXPLAIN_ASTNODE_H
#define EXPLAIN_ASTNODE_H

#include <string>
#include <vector>

#include <llvm/IR/Value.h>
#include "../Visitor/Visitor.h"

namespace explain {

using EntryList = std::vector<Entry *>;
using ExpressionList = std::vector<Expression *>;
using IdentifierList = std::vector<Identifier *>;
using StatementList = std::vector<Statement *>;

class ASTNode
{
public:
    virtual ~ASTNode() = default;

    virtual llvm::Value *generateCode() = 0;
    virtual std::string toString() = 0;

    virtual void accept(Visitor&) = 0;
};

}

#endif //EXPLAIN_ASTNODE_H
