%{
#define YYERROR_VERBOSE 1

#include <string>
#include <stack>

#include "AST/ASTNode.h"
#include "parser.h"

#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)

int yycolumn = 1;

extern "C" int yywrap {
    return 1;
}

int yyerror(const char *s) {
    printf("error %s in '%s' at line %d, column %d\n",
        yytext, yylineno, yycolumn);

    printf("\tparsed loc %d.%d-%d.%d\n",
        yyloc.first_line, yyloc.first_column,
        yyloc.last_line, yyloc.last_column);

    return 1;
}

}%

%option yylineno

digit   [0-9]
dot     ".";
float   {digit}* {dot} {digit}*;
int     {digit}+;
num     {float} | {int};

%%

[ \t\r\n]+  /* ignored */;

"if"        return TOKEN(TIF);
"else"      return TOKEN(TELSE);
"endi"      return TOKEN(TENDI);
"while"     return TOKEN(TWHILE);
"endw"      return TOKEN(TENDW);
"fun"       return TOKEN(TFUN);
"endf"      return TOKEN(TENDF);
"or"        return TOKEN(TOR);
"and"       return TOKEN(TAND);
"return"    return TOKEN(TRETURN);
"input"     return TOKEN(TINPUT);
"output"    return TOKEN(TOUTPUT);

[a-zA-Z]+   SAVE_TOKEN; return TOKEN(TID);
{num}       SAVE_TOKEN; return TOKEN(TNUM);

";"         return TOKEN(TSCOL);
{dot}       return TOKEN(TDOT);
"("         return TOKEN(TLPAR);
")"         return TOKEN(TRPAR);
","         return TOKEN(TCOMMA);
":="        return TOKEN(TASSIGN);
"+"         return TOKEN(TPLUS);
"-"         return TOKEN(TMINUS);
"*"         return TOKEN(TTIMES);
"/"         return TOKEN(TDIV);
"<"         return TOKEN(TLT);
"<="        return TOKEN(TLTEQ);
"=="        return TOKEN(TEQ);
">="        return TOKEN(TGTEQ);
">"         return TOKEN(TGT);
"!"         return TOKEN(TNOT);

. {
    printf("illegal character: %s\n", yytext);
    yyterminate();
}

%%
