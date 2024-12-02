/* balbismo.l */
%{
#include "ast.h"
#include "balbismo.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
void yyerror(const char *s);
%}

/* Definitions and rules */
%%
[ \t\r\n]+                      { /* Skip whitespace */ }
"//".*                          { /* Skip single-line comments */ }
"/*"([^*]|[*][^/])*"*/"         { /* Skip multi-line comments */ }

"int"                           { return INT; }
"float"                         { return FLOAT; }
"printf"                        { return PRINTF; }
"if"                            { return IF; }
"else"                          { return ELSE; }
"while"                         { return WHILE; }
"return"                        { return RETURN; }

"=="                            { return EQUAL_EQUAL; }
"!="                            { return NOT_EQUAL; }
">="                            { return GREATER_EQUAL; }
"<="                            { return LESS_EQUAL; }
"&&"                            { return AND_OP; }
"||"                            { return OR_OP; }
"!"                             { return NOT_OP; }
">"                             { return GREATER; }
"<"                             { return LESS; }
"="                             { return '='; }
"+"                             { return '+'; }
"-"                             { return '-'; }
"*"                             { return '*'; }
"/"                             { return '/'; }
"%"                             { return '%'; }

"("                             { return '('; }
")"                             { return ')'; }
"{"                             { return '{'; }
"}"                             { return '}'; }
"["                             { return '['; }
"]"                             { return ']'; }
";"                             { return ';'; }
","                             { return ','; }

\"([^\"\n\\]|\\.)*\"            {
                                    size_t len = strlen(yytext);
                                    /* Allocate buffer for string without quotes */
                                    yylval.str = (char*)malloc(len - 1); /* len - 2 + 1 for null terminator */
                                    if (yylval.str == NULL) {
                                        fprintf(stderr, "Memory allocation failed for string literal\n");
                                        exit(1);
                                    }
                                    /* Copy the string without the first and last character (the quotes) */
                                    strncpy(yylval.str, yytext + 1, len - 2);
                                    yylval.str[len - 2] = '\0'; /* Null terminate */
                                    return STRING_LITERAL;
                                }

[0-9]+\.[0-9]+                  {
                                    yylval.str = strdup(yytext);
                                    return FLOAT_LITERAL;
                                }
[0-9]+                          {
                                    yylval.str = strdup(yytext);
                                    return INT_LITERAL;
                                }

[a-zA-Z_][a-zA-Z0-9_]*          {
                                    yylval.str = strdup(yytext);
                                    return IDENTIFIER;
                                }

.                               {
                                    fprintf(stderr, "Unrecognized character: %s\n", yytext);
                                    exit(1);
                                }
%%
int yywrap() {
    return 1;
}
