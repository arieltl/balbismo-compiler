%{
#include "balbismo.tab.h"
%}

%option noyywrap

%%

[ \t\n]+                ;  // Ignore whitespace

"int"                   { yylval.str = strdup(yytext); return INT; }
"float"                 { yylval.str = strdup(yytext); return FLOAT; }
"printf"                { yylval.str = strdup(yytext); return PRINTF; }

"="                     { return '='; }
"+"                     { return '+'; }
"-"                     { return '-'; }
"*"                     { return '*'; }
"/"                     { return '/'; }
"("                     { return '('; }
")"                     { return ')'; }
"{"                     { return '{'; }
"}"                     { return '}'; }
";"                     { return ';'; }

[0-9]+\.[0-9]+          { yylval.str = strdup(yytext); return FLOAT_LITERAL; }
[0-9]+                  { yylval.str = strdup(yytext); return INT_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }

.                       { printf("Unexpected character: %s\n", yytext); }

%%
