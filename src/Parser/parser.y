%skeleton "lalr1.cc"
%require "3.2"

%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define parse.trace
%define parse.error verbose

%code requires {

#include "../src/AST/Conditional/Conditional.h"
#include "../src/AST/Conditional/ConditionalBinaryOp.h"
#include "../src/AST/Conditional/ConditionalCompOp.h"
#include "../src/AST/Conditional/ConditionalUnaryOp.h"
#include "../src/AST/Expression/Expression.h"
#include "../src/AST/Expression/ExpressionBinaryOp.h"
#include "../src/AST/Expression/ExpressionFunctionCall.h"
#include "../src/AST/Expression/ExpressionIdentifier.h"
#include "../src/AST/Expression/ExpressionLiteral.h"
#include "../src/AST/Identifier/Identifier.h"
#include "../src/AST/Misc/Operator.h"
#include "../src/AST/Statement/AssignmentStatement.h"
#include "../src/AST/Statement/IOStatement.h"
#include "../src/AST/Statement/IfStatement.h"
#include "../src/AST/Statement/ReturnStatement.h"
#include "../src/AST/Statement/Statement.h"
#include "../src/AST/Statement/WhileStatement.h"

}

%{
#include <stdio.h>
#include <cstdlib>

extern int yylex();
int yyerror(const char *s);

%}

%token <std::string> TID TNUM
%token <token> TIF TELSE TENDI TWHILE TENDW TFUN TENDF
%token <token> TOR TAND TRETURN TINPUT TOUTPUT
%token <token> TSCOL TLPAR TRPAR TCOMMA TASSIGN TPLUS TMINUS TTIMES TDIV
%token <token> TLT TLTEQ TEQ TGTEQ TGT TNOT

%type <explain::Identifier *> ident
%type <explain::BlockStatement *> block_stmt
%type <explain::Statement *> assignment_stmt if_stmt while_stmt return_stmt io_stmt
%type <explain::Expression *> expr expr_binop
%type <explain::Conditional *> cond cond_unop cond_binop cond_compop
%type <explain::Operator> comp_op

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TTIMES TDIV

/* Operator precedence for logical operators */
%left TAND
%left TOR
%left TNOT

%start file_input

%%

file_input
    : entries
    ;


entries
    : entry
    | entries entry
    ;


entry
    : stmt TSCOL
    | func_decl TSCOL
    ;


stmt
    : assignment_stmt
    | if_stmt
    | while_stmt
    | return_stmt
    | io_stmt
    ;


block_stmt
    : stmt TSCOL        { $$ = new explain::BlockStatement();
                          $$->createStatement($<stmt>1); }
    | block_stmt stmt TSCOL
                        { $1->createStatement($<stmt>2); }
    ;


ident
    : TID               { $$ = new explain::Identifier($1); }
    ;


func_decl
    : TFUN ident TLPAR func_decl_args TRPAR block_stmt TENDF
                        { $$ = new explain::FunctionDeclaration($2, $4, $6); }
    ;


func_call
    : ident TLPAR func_call_args TRPAR
                        { $$ = new explain::ExpressionFunctionCall($1, $3); }
    ;


func_decl_args
    : /* no argument */ { $$ = new explain::FormalParameterList(); }
    | decl_arg_list
    ;


func_call_args
    : /* no argument */ { $$ = new explain::ActualParameterList(); }
    | call_arg_list
    ;


decl_arg_list
    : ident             { $$ = new explain::FormalParameterList();
                          $$->addParameter($1); }
    | decl_arg_list TCOMMA ident
                        { $1->addParameter($3); }
    ;


call_arg_list
    : expr              { $$ = new explain::ActualParameterList();
                          $$->addParameter($1); }
    | call_arg_list TCOMMA expr
                        { $1->addParameter($3); }
    ;


assignment_stmt
    : ident TASSIGN expr  { $$ = new explain::AssignmentStatement($1, $3); }
    ;


if_stmt
    : TIF cond block_stmt TELSE block_stmt TENDI
                        { $$ = new explain::IfStatement($2, $3, $5);      }
    | TIF cond block_stmt TENDI
                        { $$ = new explain::IfStatement($2, $3, nullptr); }
    ;


while_stmt
    : TWHILE cond block_stmt TENDW
                        { $$ = new explain::WhileStatement($2, $3); }
    ;


return_stmt
    : TRETURN expr      { $$ = new explain::ReturnStatement($2); }
    ;


io_stmt
    : TINPUT ident      { $$ = new explain::IOStatement(explain::Operator::INPUT,  $2); }
    | TOUTPUT ident     { $$ = new explain::IOStatement(explain::Operator::OUTPUT, $2); }
    ;


expr
    : func_call
    | ident             { $$ = new explain::ExpressionIdentifier($1);                }
    | TNUM              { $$ = new explain::ExpressionLiteral(std::atof($1.c_str()); }
    | TLPAR expr TRPAR  { $$ = $2; }
    | expr_binop
    ;


expr_binop
    : expr TPLUS expr   { $$ = new explain::ExpressionBinaryOp(explain::Operator::ADD,      $1, $3); }
    | expr TMINUS expr  { $$ = new explain::ExpressionBinaryOp(explain::Operator::SUBTRACT, $1, $3); }
    | expr TTIMES expr  { $$ = new explain::ExpressionBinaryOp(explain::Operator::MULTIPLY, $1, $3); }
    | expr TDIV expr    { $$ = new explain::ExpressionBinaryOp(explain::Operator::DIVIDE,   $1, $3); }
    ;


cond
    : TLPAR cond TRPAR  { $$ = $2; }
    | cond_unop
    | cond_binop
    | cond_compop
    ;


cond_unop
    : TNOT cond         { $$ = new explain::ConditionalUnaryOp(explain::Operator::NOT, $2); }
    ;


cond_binop
    : cond TAND cond    { $$ = new explain::ConditionalBinaryOp(explain::Operator::AND, $1, $3); }
    | cond TOR cond     { $$ = new explain::ConditionalBinaryOp(explain::Operator::OR,  $1, $3); }
    ;


cond_compop
    : expr comp_op expr { $$ = new explain::ConditionalCompOp($2, $1, $3); }
    ;


comp_op
    : TLT               { $$ = explain::Operator::LT;   }
    | TLTEQ             { $$ = explain::Operator::LTEQ; }
    | TEQ               { $$ = explain::Operator::EQ;   }
    | TGTEQ             { $$ = explain::Operator::GTEQ; }
    | TGT               { $$ = explain::Operator::GT;   }
    ;

%%
