#ifndef EXPLAIN_STATEMENT_H
#define EXPLAIN_STATEMENT_H

#include "../ASTNode.h"

namespace explain {

class Statement : public ASTNode {
public:
    void accept(Visitor&) override;
};

}

#endif //EXPLAIN_STATEMENT_H
