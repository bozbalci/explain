#include "Statement.h"

namespace explain {

void
Statement::accept(Visitor& visitor)
{
    visitor.visit(this);
}


}
