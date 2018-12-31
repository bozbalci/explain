%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2.2"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <algorithm>
    #include <cctype>
    #include <string>

    #include "../src/astnode.hh"

    class driver;
}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error verbose

%code {
    #include "../src/driver.hh"
}

%define api.token.prefix {TOK_}
%token
    END      0          "end of file"
    IF       "if"
    ELSE     "else"
    ENDI     "endi"
    WHILE    "while"
    ENDW     "endw"
    FUN      "fun"
    ENDF     "endf"
    OR       "or"
    AND      "and"
    RETURN   "return"
    INPUT    "input"
    OUTPUT   "output"
    SCOL     ";"
    LPAREN   "("
    RPAREN   ")"
    COMMA    ","
    ASSIGN   ":="
    PLUS     "+"
    MINUS    "-"
    TIMES    "*"
    DIV      "/"
    LT       "<"
    LTEQ     "<="
    EQ       "=="
    GTEQ     ">="
    GT       ">"
    NOT      "!"
;

%token <std::string> IDENTIFIER "identifier"
%token <double> NUMBER "number"

%type <explain::AST::Root *> file_input entries
%type <explain::AST::Entry *> entry

%type <explain::AST::Stmt *> stmt
%type <explain::AST::FuncDecl *> func_decl

%type <explain::AST::BlockStmt *> block_stmt

%type <explain::AST::AssignmentStmt *> assignment_stmt
%type <explain::AST::IfStmt *> if_stmt
%type <explain::AST::WhileStmt *> while_stmt
%type <explain::AST::ReturnStmt *> return_stmt
%type <explain::AST::IOStmt *> io_stmt

%type <explain::AST::Expr *> expr
%type <explain::AST::ExprFuncCall *> func_call
%type <explain::AST::ExprBinOp *> expr_binop

%type <explain::AST::Cond *> cond
%type <explain::AST::CondUnOp *> cond_unop
%type <explain::AST::CondBinOp *> cond_binop
%type <explain::AST::CondCompOp *> cond_compop

%type <explain::AST::FuncDeclArgs *> func_decl_args decl_arg_list;
%type <explain::AST::FuncCallArgs *> func_call_args call_arg_list;

%type <std::string> ident
%type <double> number

%printer { yyo << $$; } <*>;

%left "+" "-"
%left "*" "/"

%left "and"
%left "or"
%left "!"

%%
%start file_input;

file_input
    : entries
        { $$ = $1; drv.root = $1; }
    ;


entries
    : entry
        { $$ = new explain::AST::Root();
          $$->entries.push_back($1); }
    | entries entry
        { $$ = $1; $$->entries.push_back($2); }
    ;


entry
    : stmt ";"
        { $$ = $1; }
    | func_decl ";"
        { $$ = $1; }
    ;


stmt
    : assignment_stmt
        { $$ = $1; }
    | if_stmt
        { $$ = $1; }
    | while_stmt
        { $$ = $1; }
    | return_stmt
        { $$ = $1; }
    | io_stmt
        { $$ = $1; }
    ;


block_stmt
    : stmt ";"
        { $$ = new explain::AST::BlockStmt();
          $$->stmts.push_back($1); }
    | block_stmt stmt ";"
        { $$ = $1; $$->stmts.push_back($2); }
    ;


ident
    : "identifier"
        { std::transform($1.begin(), $1.end(), $1.begin(),
                         [](unsigned char c) { return std::tolower(c); });
          $$ = $1; }
    ;


number
    : "number"
        { $$ = $1; }
    ;


assignment_stmt
    : ident ":=" expr
        { $$ = new explain::AST::AssignmentStmt($1, $3); }
    ;


if_stmt
    : "if" cond block_stmt "endi"
        { $$ = new explain::AST::IfStmt($2, $3, nullptr); }
    | "if" cond block_stmt "else" block_stmt "endi"
        { $$ = new explain::AST::IfStmt($2, $3, $5); }
    ;


while_stmt
    : "while" cond block_stmt "endw"
        { $$ = new explain::AST::WhileStmt($2, $3); }
    ;


return_stmt
    : "return" expr
        { $$ = new explain::AST::ReturnStmt($2); }
    ;


io_stmt
    : "input" ident
        { $$ = new explain::AST::IOStmt(explain::AST::Operator::INPUT, $2); }
    | "output" ident
        { $$ = new explain::AST::IOStmt(explain::AST::Operator::OUTPUT, $2); }
    ;


expr
    : func_call
        { $$ = $1; }
    | ident
        { $$ = new explain::AST::ExprIdent($1); }
    | number
        { $$ = new explain::AST::ExprNumber($1); }
    | "(" expr ")"
        { $$ = $2; }
    | expr_binop
        { $$ = $1; }
    ;


expr_binop
    : expr "+" expr
        { $$ = new explain::AST::ExprBinOp(explain::AST::Operator::PLUS, $1, $3); }
    | expr "-" expr
        { $$ = new explain::AST::ExprBinOp(explain::AST::Operator::MINUS, $1, $3); }
    | expr "*" expr
        { $$ = new explain::AST::ExprBinOp(explain::AST::Operator::TIMES, $1, $3); }
    | expr "/" expr
        { $$ = new explain::AST::ExprBinOp(explain::AST::Operator::DIV, $1, $3); }
    ;


cond
    : "(" cond ")"
        { $$ = $2; }
    | cond_unop
        { $$ = $1; }
    | cond_binop
        { $$ = $1; }
    | cond_compop
        { $$ = $1; }
    ;


cond_unop
    : "!" cond
        { $$ = new explain::AST::CondUnOp(explain::AST::Operator::NOT, $2); }
    ;


cond_binop
    : cond "and" cond
        { $$ = new explain::AST::CondBinOp(explain::AST::Operator::AND, $1, $3); }
    | cond "or" cond
        { $$ = new explain::AST::CondBinOp(explain::AST::Operator::OR, $1, $3); }
    ;


cond_compop
    : expr "<" expr
        { $$ = new explain::AST::CondCompOp(explain::AST::Operator::LT, $1, $3); }
    | expr "<=" expr
        { $$ = new explain::AST::CondCompOp(explain::AST::Operator::LTEQ, $1, $3); }
    | expr "==" expr
        { $$ = new explain::AST::CondCompOp(explain::AST::Operator::EQ, $1, $3); }
    | expr ">=" expr
        { $$ = new explain::AST::CondCompOp(explain::AST::Operator::GTEQ, $1, $3); }
    | expr ">" expr
        { $$ = new explain::AST::CondCompOp(explain::AST::Operator::GT, $1, $3); }
    ;

func_decl
    : "fun" ident "(" func_decl_args ")" block_stmt "endf"
        { $$ = new explain::AST::FuncDecl($2, $4, $6); }
    ;


func_call
    : ident "(" func_call_args ")"
        { $$ = new explain::AST::ExprFuncCall($1, $3); }
    ;


func_decl_args
    : %empty /* no argument */
        { $$ = new explain::AST::FuncDeclArgs(); }
    | decl_arg_list
        { $$ = $1; }
    ;


func_call_args
    : %empty /* no argument */
        { $$ = new explain::AST::FuncCallArgs(); }
    | call_arg_list
        { $$ = $1; }
    ;


decl_arg_list
    : ident
        { $$ = new explain::AST::FuncDeclArgs();
          $$->idents.push_back($1); }
    | decl_arg_list "," ident
        { $$ = $1; $$->idents.push_back($3); }
    ;


call_arg_list
    : expr
        { $$ = new explain::AST::FuncCallArgs();
          $$->exprs.push_back($1); }
    | call_arg_list "," expr
        { $$ = $1; $$->exprs.push_back($3); }
    ;
%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
    std::cerr << l << ": " << m << '\n';
}
