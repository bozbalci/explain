%{
#include <stdio.h>

#include "../src/AST/Conditional/Conditional.h"
#include "../src/AST/Conditional/ConditionalBinaryOp.h"
#include "../src/AST/Conditional/ConditionalCompOp.h"
#include "../src/AST/Conditional/ConditionalUnaryOp.h"
#include "../src/AST/Expression/Expression.h"
#include "../src/AST/Expression/ExpressionBinaryOp.h"
#include "../src/AST/Identifier/Identifier.h"
#include "../src/AST/Misc/Operator.h"
#include "../src/AST/Statement/AssignmentStatement.h"
#include "../src/AST/Statement/IOStatement.h"
#include "../src/AST/Statement/IfStatement.h"
#include "../src/AST/Statement/ReturnStatement.h"
#include "../src/AST/Statement/Statement.h"
#include "../src/AST/Statement/WhileStatement.h"

extern int yylex();
int yyerror(const char *s);


%}

%union {
    explain::BlockStatement *block;
    explain::Statement *stmt;

    explain::Identifier *ident;
    explain::Expression *expr;
    explain::Conditional *cond;

    explain::Operator op;

    std::string string;
    int token;
}

%token <string> TID TNUM
%token <token> TIF TELSE TENDI TWHILE TENDW TFUN TENDF
%token <token> TOR TAND TRETURN TINPUT TOUTPUT
%token <token> TSCOL TLPAR TRPAR TCOMMA TASSIGN TPLUS TMINUS TTIMES TDIV
%token <token> TLT TLTEQ TEQ TGTEQ TGT TNOT

%type <ident> ident
%type <block> block_stmt
%type <stmt> assignment_stmt if_stmt while_stmt return_stmt io_stmt
%type <expr> expr expr_binop
%type <cond> cond cond_unop cond_binop cond_compop
%type <op> comp_op

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
    ;


func_call
    : ident TLPAR func_call_args TRPAR
    ;


func_decl_args
    : /* no argument */
    | decl_arg_list
    ;


func_call_args
    : /* no argument */
    | call_arg_list
    ;


decl_arg_list
    : ident
    | decl_arg_list TCOMMA ident
    ;


call_arg_list
    : expr
    | call_arg_list TCOMMA expr
    ;


assignment_stmt
    : ident TASSIGN expr  { $$ = new explain::AssignmentStatement($1, $3); }
    ;


if_stmt
    : TIF cond block_stmt TELSE block_stmt TENDI
                        { $$ = new explain::IfStatement($2, $3, $5);      }
    | TIF cond block_stmt TENDI
                        { $$ = new explain::IfStatement($2, $3, nullptr); };
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
    | ident
    | TNUM
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
