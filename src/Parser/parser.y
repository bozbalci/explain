%code requires {
#define YYLTYPE_IS_DECLARED 1
}

%{
#include <stdio.h>

#include "AST/ASTNode.h"

extern int yylex();
int yyerror(const char *s);

}%

%union {
    explain::ASTNode *node;
    explain::FunctionDeclaration *func_decl;
    explain::Statement *stmt;
    explain::Expression *expr;
    explain::Identifier *ident;

    std::string raw;
    int token;
}%

%token <string> TID
%token <expr> TNUM

%token <token> TIF TELSE TENDI TWHILE TENDW TFUN TENDF
%token <token> TOR TAND TRETURN TINPUT TOUTPUT
%token <token> TSCOL TDOT TLPAR TRPAR TCOMMA TASSIGN TPLUS TMINUS TTIMES TDIV
%token <token> TLT TLT_EQ TEQ TGT_EQ TGT TNOT

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TTIMES TDIV
%left TAND TNOT

%start file_input

%%

file_input
    : /* blank */
    | entries
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
    : stmt TSCOL
    | block_stmt stmt TSCOL
    ;


func_decl
    : TFUN TID TLPAR func_decl_args TRPAR block_stmt TENDF
    ;


func_call
    : TID TLPAR func_call_args TRPAR
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
    : decl_arg
    | decl_arg_list TCOMMA decl_arg
    ;


call_arg_list
    : call_arg
    | call_arg_list TCOMMA call_arg
    ;


decl_arg
    : TID
    ;


call_arg
    : expr
    ;


assignment_stmt
    : TID TASSIGN expr  { $$ = new explain::AssignmentStatement($1, $3); }
    ;


if_stmt
    : TIF cond block_stmt TELSE block_stmt TENDI
                        { $$ = new explain::IfStatement($2, $3, $4); }
    | TIF cond block_stmt TENDI
                        { $$ = new explain::IfStatement($2, $3, nullptr);
    ;


while_stmt
    : TWHILE cond block_stmt TENDW
                        { $$ = new explain::WhileStatement($2, $3); }
    ;


return_stmt
    : TRETURN expr      { $$ = new explain::ReturnStatement($2); }
    ;


io_stmt
    : TINPUT TID        { $$ = new explain::IOStatement(Operator::INPUT,  $2); }
    | TOUTPUT TID       { $$ = new explain::IOStatement(Operator::OUTPUT, $2); }
    ;


expr
    : func_call
    | TID
    | TNUM
    | TLPAR expr TRPAR  { $$ = $2; }
    | expr_binop        { $$ = $1; }
    ;


expr_binop
    : expr TPLUS expr   { $$ = new explain::ExpressionBinaryOp(Operator::ADD,      $1, $3); }
    | expr TMINUS expr  { $$ = new explain::ExpressionBinaryOp(Operator::SUBTRACT, $1, $3); }
    | expr TTIMES expr  { $$ = new explain::ExpressionBinaryOp(Operator::MULTIPLY, $1, $3); }
    | expr TDIV expr    { $$ = new explain::ExpressionBinaryOp(Operator::DIVIDE,   $1, $3); }
    ;


cond
    : TLPAR cond TRPAR  { $$ = $2; }
    | cond_unop         { $$ = $1; }
    | cond_binop        { $$ = $1; }
    | cond_compop       { $$ = $1; }
    ;


cond_binop
    : cond TAND cond    { $$ = new explain::ConditionalBinaryOp(Operator::AND, $1, $3); }
    | cond TOR cond     { $$ = new explain::ConditionalBinaryOp(Operator::OR,  $1, $3); }
    ;


cond_compop
    : expr comp_op expr { $$ = new explain::ConditionalCompOp($2, $1, $3); }
    ;


cond_unop
    : TNOT cond         { $$ = new explain::ConditionalUnaryOp(Operator::NOT, $1); }
    ;


comp_op
    : TLT               { $$ = Operator::LT;   }
    | TLTEQ             { $$ = Operator::LTEQ; }
    | TEQ               { $$ = Operator::EQ;   }
    | TGTEQ             { $$ = Operator::GTEQ; }
    | TGT               { $$ = Operator::GT;   }
    ;

%%
