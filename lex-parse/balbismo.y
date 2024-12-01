/* balbismo.y */
%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();

ASTNode* ast_root;
%}

%union {
    char* str;
    ASTNode* ast;
}

/* Token Declarations */
%token <str> IDENTIFIER
%token <str> INT FLOAT PRINTF
%token IF ELSE WHILE

%token EQUAL_EQUAL NOT_EQUAL GREATER_EQUAL LESS_EQUAL GREATER LESS
%token AND_OP OR_OP NOT_OP

%token <str> INT_LITERAL
%token <str> FLOAT_LITERAL

/* Nonterminal Type Declarations */
%type <ast> PROGRAM BLOCK STATEMENT STATEMENT_LIST DECLARATION ASSIGNMENT PRINT IF_STATEMENT ELSE_CLAUSE WHILE_STATEMENT
%type <ast> EXPRESSION LOGICAL_OR LOGICAL_AND EQUALITY RELATIONAL ADDITIVE MULTIPLICATIVE UNARY PRIMARY
%type <ast> TYPE ARRAY_SPECIFIER
%type <ast> NUMBER
%type <str> PRIMITIVE_TYPES

/* Operator Precedence Declarations */
%right NOT_OP UMINUS          /* Highest precedence */
%left '*' '/' '%'
%left '+' '-'
%nonassoc '<' '>' GREATER_EQUAL LESS_EQUAL
%nonassoc EQUAL_EQUAL NOT_EQUAL
%left AND_OP
%left OR_OP                   /* Lowest precedence */

/* Grammar Rules */
%%
PROGRAM
    : BLOCK                { ast_root = $1; }
    ;

BLOCK
    : '{' STATEMENT_LIST '}' { $$ = create_node(NODE_BLOCK, NULL, $2->num_children, $2->children); }
    ;

STATEMENT_LIST
    : STATEMENT_LIST STATEMENT
        {
            ASTNode** new_children = realloc($1->children, sizeof(ASTNode*) * ($1->num_children + 1));
            if (new_children == NULL) {
                yyerror("Memory allocation failed for STATEMENT_LIST.");
                exit(1);
            }
            new_children[$1->num_children] = $2;
            $1->children = new_children;
            $1->num_children += 1;
            $$ = $1;
        }
    | /* Empty */
        {
            $$ = create_node(NODE_STATEMENT_LIST, NULL, 0, NULL);
        }
    ;

STATEMENT
    : DECLARATION ';'      { $$ = $1; }
    | ASSIGNMENT ';'       { $$ = $1; }
    | PRINT ';'            { $$ = $1; }
    | IF_STATEMENT         { $$ = $1; }
    | WHILE_STATEMENT      { $$ = $1; }
    | BLOCK                { $$ = $1; }
    ;

/* Declaration remains unchanged */
DECLARATION
    : TYPE IDENTIFIER
        {
            ASTNode* type_node = $1;
            ASTNode* id_node = create_node(NODE_IDENTIFIER, $2, 0, NULL);
            ASTNode* children_array[] = { type_node, id_node };
            $$ = create_node(NODE_DECLARATION, NULL, 2, children_array);
        }
    | TYPE IDENTIFIER '=' EXPRESSION
        {
            ASTNode* type_node = $1;
            ASTNode* id_node = create_node(NODE_IDENTIFIER, $2, 0, NULL);
            ASTNode* expr_node = $4;
            ASTNode* children_array[] = { type_node, id_node, expr_node };
            $$ = create_node(NODE_DECLARATION, NULL, 3, children_array);
        }
    ;

/* Type and Array Specifier remain unchanged */
TYPE
    : PRIMITIVE_TYPES ARRAY_SPECIFIER
        {
            if ($2 != NULL) {
                ASTNode* type_node = create_node(NODE_TYPE, $1, 0, NULL);
                ASTNode* children_array[] = { type_node, $2 };
                $$ = create_node(NODE_ARRAY_TYPE, NULL, 2, children_array);
            } else {
                $$ = create_node(NODE_TYPE, $1, 0, NULL);
            }
        }
    ;

ARRAY_SPECIFIER
    : '[' ']'               /* For int[] */
        {
            $$ = create_node(NODE_ARRAY_SPECIFIER, NULL, 0, NULL);
        }
    | '[' EXPRESSION ']'    /* For int[4] */
        {
            ASTNode* size_node = $2;
            $$ = create_node(NODE_ARRAY_SPECIFIER, NULL, 1, &size_node);
        }
    | /* Empty */
        { $$ = NULL; }
    ;

/* Updated ASSIGNMENT rule */
ASSIGNMENT
    : IDENTIFIER '=' EXPRESSION
        {
            ASTNode* id_node = create_node(NODE_IDENTIFIER, $1, 0, NULL);
            ASTNode* expr_node = $3;
            ASTNode* children_array[] = { id_node, expr_node };
            $$ = create_node(NODE_ASSIGNMENT, NULL, 2, children_array);
        }
    | IDENTIFIER '[' EXPRESSION ']' '=' EXPRESSION
        {
            ASTNode* index_node = $3;
            ASTNode* lhs_children[] = { index_node };
            ASTNode* indexed_id_node = create_node(NODE_INDEXED_IDENTIFIER, $1, 1, lhs_children);
            ASTNode* expr_node = $6;
            ASTNode* children_array[] = { indexed_id_node, expr_node };
            $$ = create_node(NODE_ASSIGNMENT, NULL, 2, children_array);
        }
    ;

PRINT
    : PRINTF '(' EXPRESSION ')'
        {
            ASTNode* expr_node = $3;
            ASTNode* children_array[] = { expr_node };
            $$ = create_node(NODE_PRINT, NULL, 1, children_array);
        }
    ;

IF_STATEMENT
    : IF '(' EXPRESSION ')' BLOCK
        {
            ASTNode* condition = $3;
            ASTNode* if_block = $5;
            ASTNode* children_array[] = { condition, if_block };
            $$ = create_node(NODE_IF_STATEMENT, NULL, 2, children_array);
        }
    | IF '(' EXPRESSION ')' BLOCK ELSE_CLAUSE
        {
            ASTNode* condition = $3;
            ASTNode* if_block = $5;
            ASTNode* else_clause = $6;
            ASTNode* children_array[] = { condition, if_block, else_clause };
            $$ = create_node(NODE_IF_STATEMENT, NULL, 3, children_array);
        }
    ;

ELSE_CLAUSE
    : ELSE BLOCK
        {
            $$ = $2;
        }
    | ELSE IF_STATEMENT
        {
            $$ = $2;
        }
    ;

WHILE_STATEMENT
    : WHILE '(' EXPRESSION ')' BLOCK
        {
            ASTNode* condition = $3;
            ASTNode* body = $5;
            ASTNode* children_array[] = { condition, body };
            $$ = create_node(NODE_WHILE_STATEMENT, NULL, 2, children_array);
        }
    ;

PRIMITIVE_TYPES
    : INT                  { $$ = $1; }
    | FLOAT                { $$ = $1; }
    ;

/* Expression Rules remain the same */
EXPRESSION
    : LOGICAL_OR           { $$ = $1; }
    ;

LOGICAL_OR
    : LOGICAL_OR OR_OP LOGICAL_AND
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_BOOL_BIN_OP, "||", 2, children_array);
        }
    | LOGICAL_AND
        { $$ = $1; }
    ;

LOGICAL_AND
    : LOGICAL_AND AND_OP EQUALITY
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_BOOL_BIN_OP, "&&", 2, children_array);
        }
    | EQUALITY
        { $$ = $1; }
    ;

EQUALITY
    : EQUALITY EQUAL_EQUAL RELATIONAL
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_REL_OP, "==", 2, children_array);
        }
    | EQUALITY NOT_EQUAL RELATIONAL
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_REL_OP, "!=", 2, children_array);
        }
    | RELATIONAL
        { $$ = $1; }
    ;

RELATIONAL
    : RELATIONAL GREATER ADDITIVE
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_REL_OP, ">", 2, children_array);
        }
    | RELATIONAL LESS ADDITIVE
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_REL_OP, "<", 2, children_array);
        }
    | RELATIONAL GREATER_EQUAL ADDITIVE
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_REL_OP, ">=", 2, children_array);
        }
    | RELATIONAL LESS_EQUAL ADDITIVE
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_REL_OP, "<=", 2, children_array);
        }
    | ADDITIVE
        { $$ = $1; }
    ;

ADDITIVE
    : ADDITIVE '+' MULTIPLICATIVE
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_BIN_OP, "+", 2, children_array);
        }
    | ADDITIVE '-' MULTIPLICATIVE
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_BIN_OP, "-", 2, children_array);
        }
    | MULTIPLICATIVE
        { $$ = $1; }
    ;

MULTIPLICATIVE
    : MULTIPLICATIVE '*' UNARY
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_BIN_OP, "*", 2, children_array);
        }
    | MULTIPLICATIVE '/' UNARY
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_BIN_OP, "/", 2, children_array);
        }
    | MULTIPLICATIVE '%' UNARY
        {
            ASTNode* children_array[] = { $1, $3 };
            $$ = create_node(NODE_BIN_OP, "%", 2, children_array);
        }
    | UNARY
        { $$ = $1; }
    ;

UNARY
    : '+' UNARY %prec UMINUS
        {
            ASTNode* children_array[] = { $2 };
            $$ = create_node(NODE_UN_OP, "+", 1, children_array);
        }
    | '-' UNARY %prec UMINUS
        {
            ASTNode* children_array[] = { $2 };
            $$ = create_node(NODE_UN_OP, "-", 1, children_array);
        }
    | NOT_OP UNARY
        {
            ASTNode* children_array[] = { $2 };
            $$ = create_node(NODE_BOOL_UN_OP, "!", 1, children_array);
        }
    | PRIMARY
        { $$ = $1; }
    ;

/* Updated PRIMARY to handle IndexedIdentifier */
PRIMARY
    : IDENTIFIER
        {
            $$ = create_node(NODE_IDENTIFIER, $1, 0, NULL);
        }
    | IDENTIFIER '[' EXPRESSION ']'
        {
            ASTNode* index_node = $3;
            ASTNode* children_array[] = { index_node };
            $$ = create_node(NODE_INDEXED_IDENTIFIER, $1, 1, children_array);
        }
    | NUMBER
        { $$ = $1; }
    | '(' EXPRESSION ')'
        { $$ = $2; }
    ;

NUMBER
    : INT_LITERAL
        {
            $$ = create_node(NODE_INT_LITERAL, $1, 0, NULL);
        }
    | FLOAT_LITERAL
        {
            $$ = create_node(NODE_FLOAT_LITERAL, $1, 0, NULL);
        }
    ;

%%

/* C Code Section remains unchanged */

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char** argv) {
    FILE* yaml_file = NULL;

    if (argc > 2 && strcmp(argv[1], "-o") == 0) {
        yaml_file = fopen(argv[2], "w");
        if (yaml_file == NULL) {
            fprintf(stderr, "Error: Cannot open output file %s\n", argv[2]);
            return 1;
        }
    } else {
        yaml_file = stdout;
    }

    if (yyparse() == 0) {
        if (ast_root == NULL) {
            fprintf(stderr, "Error: AST root is NULL.\n");
        } else {
            printf("\nAbstract Syntax Tree (YAML):\n");
            print_ast_yaml(yaml_file, ast_root, 0);
        }

        if (yaml_file != stdout)
            fclose(yaml_file);

        free_ast(ast_root);
    }

    return 0;
}
