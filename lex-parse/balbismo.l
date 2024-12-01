/* balbismo.l */
%{
#include "ast.h"
#include "balbismo.tab.h" /* Include Bison's header after ast.h */
#include <string.h>
#include <stdlib.h>

void yyerror(const char *s);
%}

%%

"int"               { yylval.str = strdup("int"); return INT; }
"float"             { yylval.str = strdup("float"); return FLOAT; }
"printf"            { yylval.str = strdup("printf"); return PRINTF; }
"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }   // Added this line
"=="                { return EQUAL_EQUAL; }
"!="                { return NOT_EQUAL; }
">="                { return GREATER_EQUAL; }
"<="                { return LESS_EQUAL; }
">"                 { return GREATER; }
"<"                 { return LESS; }
"&&"                { return AND_OP; }
"||"                { return OR_OP; }
"!"                 { return NOT_OP; }
"+"                 { return '+'; }
"-"                 { return '-'; }
"*"                 { return '*'; }
"/"                 { return '/'; }
"%"                 { return '%'; }
"="                 { return '='; }
";"                 { return ';'; }
"{"                 { return '{'; }
"}"                 { return '}'; }
"("                 { return '('; }
")"                 { return ')'; }
"["                 { return '['; }
"]"                 { return ']'; }

[0-9]+\.[0-9]+      { 
                        yylval.str = strdup(yytext); 
                        printf("Lexer: FLOAT_LITERAL = %s\n", yylval.str);
                        return FLOAT_LITERAL; 
                    }
[0-9]+              { 
                        yylval.str = strdup(yytext); 
                        printf("Lexer: INT_LITERAL = %s\n", yylval.str);
                        return INT_LITERAL; 
                    }
[a-zA-Z_][a-zA-Z0-9_]* { 
                        yylval.str = strdup(yytext); 
                        printf("Lexer: IDENTIFIER = %s\n", yylval.str);
                        return IDENTIFIER; 
                    }
[ \t\n]+            ; 
.                   { 
                        printf("Lexer: Unknown character '%s'\n", yytext); 
                        yyerror("Unknown character"); 
                    }

%%

int yywrap() {
    return 1;
}
