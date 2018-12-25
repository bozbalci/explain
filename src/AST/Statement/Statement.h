#ifndef EXPLAIN_STATEMENT_H
#define EXPLAIN_STATEMENT_H

#include "../ASTNode.h"
#include "../Entry.h"

namespace explain {

class Statement : public Entry {
public:
    void accept(Visitor&) override;
};

}

#endif //EXPLAIN_STATEMENT_H
