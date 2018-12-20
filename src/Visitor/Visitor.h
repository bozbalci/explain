#ifndef EXPLAIN_VISITOR_H
#define EXPLAIN_VISITOR_H

#include "../../AST/Conditional/ConditionalBinaryOp.h"
#include "../../AST/Conditional/ConditionalCompOp.h"
#include "../../AST/Conditional/ConditionalUnaryOp.h"
#include "../../AST/Function/FunctionDeclaration.h"
#include "../../AST/Expression/Expression.h"
#include "../../AST/Expression/ExpressionBinaryOp.h"
#include "../../AST/Statement/AssignmentStatement.h"
#include "../../AST/Statement/BlockStatement.h"
#include "../../AST/Statement/IfStatement.h"
#include "../../AST/Statement/IOStatement.h"
#include "../../AST/Statement/ReturnStatement.h"
#include "../../AST/Statement/Statement.h"
#include "../../AST/Statement/WhileStatement.h"
#include "../../AST/Identifier/Identifier.h"

namespace explain {

class AssignmentStatement;
class BlockStatement;
class Conditional;
class ConditionalBinaryOp;
class ConditionalCompOp;
class ConditionalUnaryOp;
class Expression;
class ExpressionBinaryOp;
class IfStatement;
class IOStatement;
class ReturnStatement;
class Statement;
class FunctionDeclaration;
class WhileStatement;
class Identifier;

class Visitor
{
public:
    virtual void visit(AssignmentStatement *) = 0;
    virtual void visit(BlockStatement *) = 0;
    virtual void visit(Conditional *) = 0;
    virtual void visit(ConditionalBinaryOp *) = 0;
    virtual void visit(ConditionalCompOp *) = 0;
    virtual void visit(ConditionalUnaryOp *) = 0;
    virtual void visit(Expression *) = 0;
    virtual void visit(ExpressionBinaryOp *) = 0;
    virtual void visit(IfStatement *) = 0;
    virtual void visit(IOStatement *) = 0;
    virtual void visit(ReturnStatement *) = 0;
    virtual void visit(Statement *) = 0;
    virtual void visit(WhileStatement *) = 0;
    virtual void visit(FunctionDeclaration *) = 0;
    virtual void visit(Identifier *) = 0;
};

}

#endif //EXPLAIN_VISITOR_H
