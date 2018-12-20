%{
#define YYERROR_VERBOSE 1

#include <string>
#include <stack>

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

#include "parser.hh"

#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)

int yycolumn = 1;
extern "C" int yywrap { return 1; }

int
yyerror(const char *s)
{
    printf("error %s in '%s' at line %d, column %d\n",
        yytext, yylineno, yycolumn);

    printf("\tparsed loc %d.%d-%d.%d\n",
        yyloc.first_line, yyloc.first_column,
        yyloc.last_line, yyloc.last_column);

    return 1;
}
%}

%%
[ \t\r\n]+  /* ignored */;
"if"                return TOKEN(TIF);
"else"              return TOKEN(TELSE);
"endi"              return TOKEN(TENDI);
"while"             return TOKEN(TWHILE);
"endw"              return TOKEN(TENDW);
"fun"               return TOKEN(TFUN);
"endf"              return TOKEN(TENDF);
"or"                return TOKEN(TOR);
"and"               return TOKEN(TAND);
"return"            return TOKEN(TRETURN);
"input"             return TOKEN(TINPUT);
"output"            return TOKEN(TOUTPUT);
[a-zA-Z]+           SAVE_TOKEN; return TOKEN(TID);
[0-9]*\.?[0-9]+     SAVE_TOKEN; return TOKEN(TNUM);
";"                 return TOKEN(TSCOL);
"("                 return TOKEN(TLPAR);
")"                 return TOKEN(TRPAR);
","                 return TOKEN(TCOMMA);
":="                return TOKEN(TASSIGN);
"+"                 return TOKEN(TPLUS);
"-"                 return TOKEN(TMINUS);
"*"                 return TOKEN(TTIMES);
"/"                 return TOKEN(TDIV);
"<"                 return TOKEN(TLT);
"<="                return TOKEN(TLTEQ);
"=="                return TOKEN(TEQ);
">="                return TOKEN(TGTEQ);
">"                 return TOKEN(TGT);
"!"                 return TOKEN(TNOT);
.                   printf("illegal character: %s\n", yytext); yyterminate();
%%
