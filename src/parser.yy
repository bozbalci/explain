%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2.2"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <algorithm>
    #include <cctype>
    #include <memory>
    #include <string>
    #include <utility>

    #include "../src/ast.hh"

    class Driver;
}

// The parsing context.
%param { Driver& drv }

%locations

%define parse.trace
%define parse.error verbose

%code {
    #include "../src/driver.hh"

    template<typename D, typename B>
    std::unique_ptr<D> downcast(std::unique_ptr<B> &&p)
    {
        auto d = static_cast<D *>(p.release());
        return std::unique_ptr<D>(d);
    }
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

%type <std::unique_ptr<explain::AST::Root>> file_input entries
%type <std::unique_ptr<explain::AST::Entry>> entry

%type <std::unique_ptr<explain::AST::Stmt>> stmt
%type <std::unique_ptr<explain::AST::FuncDecl>> func_decl
%type <std::unique_ptr<explain::AST::BlockStmt>> block_stmt

%type <std::unique_ptr<explain::AST::AssignmentStmt>> assignment_stmt
%type <std::unique_ptr<explain::AST::IfStmt>> if_stmt
%type <std::unique_ptr<explain::AST::WhileStmt>> while_stmt
%type <std::unique_ptr<explain::AST::ReturnStmt>> return_stmt
%type <std::unique_ptr<explain::AST::IOStmt>> io_stmt

%type <std::unique_ptr<explain::AST::Expr>> expr
%type <std::unique_ptr<explain::AST::ExprFuncCall>> func_call
%type <std::unique_ptr<explain::AST::ExprBinOp>> expr_binop

%type <std::unique_ptr<explain::AST::Cond>> cond
%type <std::unique_ptr<explain::AST::CondUnOp>> cond_unop
%type <std::unique_ptr<explain::AST::CondBinOp>> cond_binop
%type <std::unique_ptr<explain::AST::CondCompOp>> cond_compop

%type <std::unique_ptr<explain::AST::FuncDeclArgs>> func_decl_args decl_arg_list;
%type <std::unique_ptr<explain::AST::FuncCallArgs>> func_call_args call_arg_list;

%type <std::string> ident
%type <double> number

%left "+" "-"
%left "*" "/"

%left "and"
%left "or"
%left "!"

%%
%start file_input;

file_input
    : entries
        { $$ = std::move($1); drv.root = std::move($$); }
    ;


entries
    : entry
        { $$ = std::make_unique<explain::AST::Root>();
          if ($1->getNodeType() == explain::AST::NodeType::FUNC_DECL)
              $$->funcDecls.push_back(downcast<explain::AST::FuncDecl, explain::AST::Entry>(std::move($1)));
          else
              $$->topLevelStmts.push_back(downcast<explain::AST::Stmt, explain::AST::Entry>(std::move($1)));
        }
    | entries entry
        { $$ = std::move($1);
          if ($2->getNodeType() == explain::AST::NodeType::FUNC_DECL)
              $$->funcDecls.push_back(downcast<explain::AST::FuncDecl, explain::AST::Entry>(std::move($2)));
          else
              $$->topLevelStmts.push_back(downcast<explain::AST::Stmt, explain::AST::Entry>(std::move($2)));
        }
    ;


entry
    : stmt ";"
        { $$ = std::move($1); }
    | func_decl ";"
        { $$ = std::move($1); }
    ;


stmt
    : assignment_stmt
        { $$ = std::move($1); }
    | if_stmt
        { $$ = std::move($1); }
    | while_stmt
        { $$ = std::move($1); }
    | return_stmt
        { $$ = std::move($1); }
    | io_stmt
        { $$ = std::move($1); }
    ;


block_stmt
    : stmt ";"
        { $$ = std::make_unique<explain::AST::BlockStmt>();
          $$->stmts.push_back(std::move($1)); }
    | block_stmt stmt ";"
        { $$ = std::move($1); $$->stmts.push_back(std::move($2)); }
    ;


ident
    : "identifier"
        { std::transform($1.begin(), $1.end(), $1.begin(),
                         [](unsigned char c) { return std::tolower(c); });
          $$ = std::move($1); }
    ;


number
    : "number"
        { $$ = $1; }
    ;


assignment_stmt
    : ident ":=" expr
        { $$ = std::make_unique<explain::AST::AssignmentStmt>(std::move($1), std::move($3)); }
    ;


if_stmt
    : "if" cond block_stmt "endi"
        { $$ = std::make_unique<explain::AST::IfStmt>(std::move($2), std::move($3), nullptr); }
    | "if" cond block_stmt "else" block_stmt "endi"
        { $$ = std::make_unique<explain::AST::IfStmt>(std::move($2), std::move($3), std::move($5)); }
    ;


while_stmt
    : "while" cond block_stmt "endw"
        { $$ = std::make_unique<explain::AST::WhileStmt>(std::move($2), std::move($3)); }
    ;


return_stmt
    : "return" expr
        { $$ = std::make_unique<explain::AST::ReturnStmt>(std::move($2)); }
    ;


io_stmt
    : "input" ident
        { $$ = std::make_unique<explain::AST::IOStmt>(explain::AST::Operator::INPUT, std::move($2)); }
    | "output" ident
        { $$ = std::make_unique<explain::AST::IOStmt>(explain::AST::Operator::OUTPUT, std::move($2)); }
    ;


expr
    : func_call
        { $$ = std::move($1); }
    | ident
        { $$ = std::make_unique<explain::AST::ExprIdent>(std::move($1)); }
    | number
        { $$ = std::make_unique<explain::AST::ExprNumber>($1); }
    | "(" expr ")"
        { $$ = std::move($2); }
    | expr_binop
        { $$ = std::move($1); }
    ;


expr_binop
    : expr "+" expr
        { $$ = std::make_unique<explain::AST::ExprBinOp>(explain::AST::Operator::PLUS, std::move($1), std::move($3)); }
    | expr "-" expr
        { $$ = std::make_unique<explain::AST::ExprBinOp>(explain::AST::Operator::MINUS, std::move($1), std::move($3)); }
    | expr "*" expr
        { $$ = std::make_unique<explain::AST::ExprBinOp>(explain::AST::Operator::TIMES, std::move($1), std::move($3)); }
    | expr "/" expr
        { $$ = std::make_unique<explain::AST::ExprBinOp>(explain::AST::Operator::DIV, std::move($1), std::move($3)); }
    ;


cond
    : "(" cond ")"
        { $$ = std::move($2); }
    | cond_unop
        { $$ = std::move($1); }
    | cond_binop
        { $$ = std::move($1); }
    | cond_compop
        { $$ = std::move($1); }
    ;


cond_unop
    : "!" cond
        { $$ = std::make_unique<explain::AST::CondUnOp>(explain::AST::Operator::NOT, std::move($2)); }
    ;


cond_binop
    : cond "and" cond
        { $$ = std::make_unique<explain::AST::CondBinOp>(explain::AST::Operator::AND, std::move($1), std::move($3)); }
    | cond "or" cond
        { $$ = std::make_unique<explain::AST::CondBinOp>(explain::AST::Operator::OR, std::move($1), std::move($3)); }
    ;


cond_compop
    : expr "<" expr
        { $$ = std::make_unique<explain::AST::CondCompOp>(explain::AST::Operator::LT, std::move($1), std::move($3)); }
    | expr "<=" expr
        { $$ = std::make_unique<explain::AST::CondCompOp>(explain::AST::Operator::LTEQ, std::move($1), std::move($3)); }
    | expr "==" expr
        { $$ = std::make_unique<explain::AST::CondCompOp>(explain::AST::Operator::EQ, std::move($1), std::move($3)); }
    | expr ">=" expr
        { $$ = std::make_unique<explain::AST::CondCompOp>(explain::AST::Operator::GTEQ, std::move($1), std::move($3)); }
    | expr ">" expr
        { $$ = std::make_unique<explain::AST::CondCompOp>(explain::AST::Operator::GT, std::move($1), std::move($3)); }
    ;

func_decl
    : "fun" ident "(" func_decl_args ")" block_stmt "endf"
        { $$ = std::make_unique<explain::AST::FuncDecl>(std::move($2), std::move($4), std::move($6)); }
    ;


func_call
    : ident "(" func_call_args ")"
        { $$ = std::make_unique<explain::AST::ExprFuncCall>(std::move($1), std::move($3)); }
    ;


func_decl_args
    : %empty /* no argument */
        { $$ = std::make_unique<explain::AST::FuncDeclArgs>(); }
    | decl_arg_list
        { $$ = std::move($1); }
    ;


func_call_args
    : %empty /* no argument */
        { $$ = std::make_unique<explain::AST::FuncCallArgs>(); }
    | call_arg_list
        { $$ = std::move($1); }
    ;


decl_arg_list
    : ident
        { $$ = std::make_unique<explain::AST::FuncDeclArgs>();
          $$->idents.push_back(std::move($1)); }
    | decl_arg_list "," ident
        { $$ = std::move($1); $$->idents.push_back(std::move($3)); }
    ;


call_arg_list
    : expr
        { $$ = std::make_unique<explain::AST::FuncCallArgs>();
          $$->exprs.push_back(std::move($1)); }
    | call_arg_list "," expr
        { $$ = std::move($1); $$->exprs.push_back(std::move($3)); }
    ;
%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
    std::cerr << l << ": " << m << '\n';
}
