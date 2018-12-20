#ifndef EXPLAIN_EXPRESSION_H
#define EXPLAIN_EXPRESSION_H

#include "../ASTNode.h"
#include "../Misc/Operator.h"

namespace explain {

class Expression : public ASTNode
{
public:
    void accept(Visitor&) override;
};

}

#endif //EXPLAIN_EXPRESSION_H
