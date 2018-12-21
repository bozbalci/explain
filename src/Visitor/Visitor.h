#ifndef EXPLAIN_VISITOR_H
#define EXPLAIN_VISITOR_H

namespace explain {

class ActualParameterList;
class AssignmentStatement;
class BlockStatement;
class Conditional;
class ConditionalBinaryOp;
class ConditionalCompOp;
class ConditionalUnaryOp;
class Expression;
class ExpressionBinaryOp;
class ExpressionFunctionCall;
class ExpressionIdentifier;
class ExpressionLiteral;
class FormalParameterList;
class FunctionDeclaration;
class IOStatement;
class Identifier;
class IfStatement;
class ReturnStatement;
class Statement;
class WhileStatement;

class Visitor
{
public:
    virtual void visit(ActualParameterList *) = 0;
    virtual void visit(AssignmentStatement *) = 0;
    virtual void visit(BlockStatement *) = 0;
    virtual void visit(Conditional *) = 0;
    virtual void visit(ConditionalBinaryOp *) = 0;
    virtual void visit(ConditionalCompOp *) = 0;
    virtual void visit(ConditionalUnaryOp *) = 0;
    virtual void visit(Expression *) = 0;
    virtual void visit(ExpressionBinaryOp *) = 0;
    virtual void visit(ExpressionFunctionCall *) = 0;
    virtual void visit(ExpressionIdentifier *) = 0;
    virtual void visit(ExpressionLiteral *) = 0;
    virtual void visit(FormalParameterList *) = 0;
    virtual void visit(FunctionDeclaration *) = 0;
    virtual void visit(IOStatement *) = 0;
    virtual void visit(IfStatement *) = 0;
    virtual void visit(ReturnStatement *) = 0;
    virtual void visit(Statement *) = 0;
    virtual void visit(WhileStatement *) = 0;
};

}

#endif //EXPLAIN_VISITOR_H
