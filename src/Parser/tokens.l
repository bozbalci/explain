%{ /* -*- C++ -*- */
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring>
    #include <string>

    #include "parser.hh"

    // Code run each time a pattern is matched
    #define YY_USER_ACTION loc.columns(yyleng);

    yy::location& loc = drv.location;
    loc.step();
%}

%option noyywrap nounput noinput batch debug

%%
[ \t]+              loc.step();
[\r\n]+             loc.lines(yyleng); loc.step();

"if"                return yy::parser::make_TIF     (loc);
"else"              return yy::parser::make_TELSE   (loc);
"endi"              return yy::parser::make_TENDI   (loc);
"while"             return yy::parser::make_TWHILE  (loc);
"endw"              return yy::parser::make_TENDW   (loc);
"fun"               return yy::parser::make_TFUN    (loc);
"endf"              return yy::parser::make_TENDF   (loc);
"or"                return yy::parser::make_TOR     (loc);
"and"               return yy::parser::make_TAND    (loc);
"return"            return yy::parser::make_TRETURN (loc);
"input"             return yy::parser::make_TINPUT  (loc);
"output"            return yy::parser::make_TOUTPUT (loc);

[a-zA-Z]+           return yy::parser::make_TID     (yytext, loc);
[0-9]*\.?[0-9]+     return yy::parser::make_TNUM    (yytext, loc);

";"                 return yy::parser::make_TSCOL   (loc);
"("                 return yy::parser::make_TLPAR   (loc);
")"                 return yy::parser::make_TRPAR   (loc);
","                 return yy::parser::make_TCOMMA  (loc);
":="                return yy::parser::make_TASSIGN (loc);
"+"                 return yy::parser::make_TPLUS   (loc);
"-"                 return yy::parser::make_TMINUS  (loc);
"*"                 return yy::parser::make_TTIMES  (loc);
"/"                 return yy::parser::make_TDIV    (loc);
"<"                 return yy::parser::make_TLT     (loc);
"<="                return yy::parser::make_TLTEQ   (loc);
"=="                return yy::parser::make_TEQ     (loc);
">="                return yy::parser::make_TGTEQ   (loc);
">"                 return yy::parser::make_TGT     (loc);
"!"                 return yy::parser::make_TNOT    (loc);

<<EOF>>             return yy::parser::make_TEOF    (loc);
.                   { throw yy::parser::syntax_error
                        (loc, "invalid character: " + std::string(yytext)); }
%%
