#ifndef EXPLAIN_ACTUALPARAMETERLIST_H
#define EXPLAIN_ACTUALPARAMETERLIST_H

#include <string>

#include <llvm/IR/Value.h>

#include "../ASTNode.h"

namespace explain {

class ActualParameterList : public ASTNode
{
    ExpressionList actualParams;
public:
    ActualParameterList();
    ~ActualParameterList() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;

    void addParameter(Expression *);
};

}

#endif //EXPLAIN_ACTUALPARAMETERLIST_H
