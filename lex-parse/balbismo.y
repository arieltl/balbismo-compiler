/* balbismo.y */
%{
#include "ast.h"          /* Include AST definitions first */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();

ASTNode* ast_root;        /* Root of the AST */
%}

%union {
    char* str;
    ASTNode* ast;
}

%token <str> IDENTIFIER
%token <str> INT FLOAT PRINTF
%token IF ELSE

%token EQUAL_EQUAL NOT_EQUAL GREATER_EQUAL LESS_EQUAL GREATER LESS
%token AND_OP OR_OP NOT_OP

%token <str> INT_LITERAL
%token <str> FLOAT_LITERAL

%type <ast> PROGRAM BLOCK STATEMENT matched_stmt unmatched_stmt DECLARATION ASSIGNMENT PRINT IF_STATEMENT
%type <ast> STATEMENT_LIST
%type <ast> EXPRESSION TERM FACTOR RELATIONAL_EXPRESSION NUMBER
%type <str> TYPES

/* Operator Precedence */
%left OR_OP
%left AND_OP
%right NOT_OP
%nonassoc EQUAL_EQUAL NOT_EQUAL GREATER LESS GREATER_EQUAL LESS_EQUAL
%left '+' '-'
%left '*' '/' '%'
%right UMINUS  /* For unary minus */

%%

PROGRAM
    : BLOCK                { ast_root = $1; }
    ;

BLOCK
    : '{' '}'              { $$ = create_node(NODE_BLOCK, NULL, 0, NULL); }
    | '{' STATEMENT_LIST '}' { $$ = create_node(NODE_BLOCK, NULL, $2->num_children, $2->children); }
    ;

STATEMENT_LIST
    : STATEMENT
        {
            ASTNode* children_array[] = { $1 };
            $$ = create_node(NODE_STATEMENT_LIST, NULL, 1, children_array);
        }
    | STATEMENT_LIST STATEMENT
        {
            ASTNode** new_children = malloc(sizeof(ASTNode*) * ($1->num_children + 1));
            if (new_children == NULL) {
                yyerror("Memory allocation failed for STATEMENT_LIST.");
                exit(1);
            }

            memcpy(new_children, $1->children, sizeof(ASTNode*) * $1->num_children);
            new_children[$1->num_children] = $2;

            ASTNode* new_list = create_node(NODE_STATEMENT_LIST, NULL, $1->num_children + 1, new_children);
            free($1->children);
            $$ = new_list;
        }
    ;

STATEMENT
    : matched_stmt      { $$ = $1; }
    | unmatched_stmt    { $$ = $1; }
    ;

matched_stmt
    : DECLARATION ';'
    | ASSIGNMENT ';'
    | PRINT ';'
    | IF_STATEMENT
    | BLOCK           /* Added to include BLOCK as a matched_stmt */
    ;

unmatched_stmt
    : IF '(' RELATIONAL_EXPRESSION ')' STATEMENT
        {
            ASTNode* condition = $3;
            ASTNode* if_block = $5;
            ASTNode* children_array[] = { condition, if_block };
            $$ = create_node(NODE_IF_STATEMENT, NULL, 2, children_array);
        }
    ;

DECLARATION
    : TYPES IDENTIFIER
        {
            ASTNode* type_node = create_node(NODE_TYPE, $1, 0, NULL);
            ASTNode* id_node = create_node(NODE_IDENTIFIER, $2, 0, NULL);
            ASTNode* children_array[] = { type_node, id_node };
            $$ = create_node(NODE_DECLARATION, NULL, 2, children_array);
        }
    | TYPES IDENTIFIER '=' RELATIONAL_EXPRESSION
        {
            ASTNode* type_node = create_node(NODE_TYPE, $1, 0, NULL);
            ASTNode* id_node = create_node(NODE_IDENTIFIER, $2, 0, NULL);
            ASTNode* expr_node = $4;
            ASTNode* children_array[] = { type_node, id_node, expr_node };
            $$ = create_node(NODE_DECLARATION, NULL, 3, children_array);
        }
    ;

ASSIGNMENT
    : IDENTIFIER '=' RELATIONAL_EXPRESSION
        {
            ASTNode* id_node = create_node(NODE_IDENTIFIER, $1, 0, NULL);
            ASTNode* expr_node = $3;
            ASTNode* children_array[] = { id_node, expr_node };
            $$ = create_node(NODE_ASSIGNMENT, NULL, 2, children_array);
        }
    ;

PRINT
    : PRINTF '(' RELATIONAL_EXPRESSION ')'
        {
            ASTNode* expr_node = $3;
            ASTNode* children_array[] = { expr_node };
            $$ = create_node(NODE_PRINT, NULL, 1, children_array);
        }
    ;

IF_STATEMENT
    : IF '(' RELATIONAL_EXPRESSION ')' matched_stmt ELSE matched_stmt
        {
            ASTNode* condition = $3;
            ASTNode* if_block = $5;
            ASTNode* else_block = $7;
            ASTNode* children_array[] = { condition, if_block, else_block };
            $$ = create_node(NODE_IF_STATEMENT, NULL, 3, children_array);
        }
    ;

TYPES
    : INT                  { $$ = $1; }
    | FLOAT                { $$ = $1; }
    ;

RELATIONAL_EXPRESSION
    : EXPRESSION
        { $$ = $1; }
    | RELATIONAL_EXPRESSION GREATER EXPRESSION
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, ">", 2, children_array);
            $$ = rel_op_node;
        }
    | RELATIONAL_EXPRESSION LESS EXPRESSION
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, "<", 2, children_array);
            $$ = rel_op_node;
        }
    | RELATIONAL_EXPRESSION GREATER_EQUAL EXPRESSION
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, ">=", 2, children_array);
            $$ = rel_op_node;
        }
    | RELATIONAL_EXPRESSION LESS_EQUAL EXPRESSION
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, "<=", 2, children_array);
            $$ = rel_op_node;
        }
    | RELATIONAL_EXPRESSION EQUAL_EQUAL EXPRESSION
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, "==", 2, children_array);
            $$ = rel_op_node;
        }
    | RELATIONAL_EXPRESSION NOT_EQUAL EXPRESSION
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, "!=", 2, children_array);
            $$ = rel_op_node;
        }
    ;

EXPRESSION
    : TERM
        { $$ = $1; }
    | EXPRESSION '+' TERM
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* bin_op_node = create_node(NODE_BIN_OP, "+", 2, children_array);
            $$ = bin_op_node;
        }
    | EXPRESSION '-' TERM
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* bin_op_node = create_node(NODE_BIN_OP, "-", 2, children_array);
            $$ = bin_op_node;
        }
    | EXPRESSION OR_OP TERM
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* bool_bin_op_node = create_node(NODE_BOOL_BIN_OP, "||", 2, children_array);
            $$ = bool_bin_op_node;
        }
    ;

TERM
    : FACTOR
        { $$ = $1; }
    | TERM '*' FACTOR
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* bin_op_node = create_node(NODE_BIN_OP, "*", 2, children_array);
            $$ = bin_op_node;
        }
    | TERM '/' FACTOR
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* bin_op_node = create_node(NODE_BIN_OP, "/", 2, children_array);
            $$ = bin_op_node;
        }
    | TERM '%' FACTOR
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* bin_op_node = create_node(NODE_BIN_OP, "%", 2, children_array);
            $$ = bin_op_node;
        }
    | TERM AND_OP FACTOR
        {
            ASTNode* children_array[] = { $1, $3 };
            ASTNode* bool_bin_op_node = create_node(NODE_BOOL_BIN_OP, "&&", 2, children_array);
            $$ = bool_bin_op_node;
        }
    ;

FACTOR
    : '+' FACTOR  %prec UMINUS
        {
            ASTNode* children_array[] = { $2 };
            ASTNode* un_op_node = create_node(NODE_UN_OP, "+", 1, children_array);
            $$ = un_op_node;
        }
    | '-' FACTOR  %prec UMINUS
        {
            ASTNode* children_array[] = { $2 };
            ASTNode* un_op_node = create_node(NODE_UN_OP, "-", 1, children_array);
            $$ = un_op_node;
        }
    | NOT_OP FACTOR
        {
            ASTNode* children_array[] = { $2 };
            ASTNode* bool_un_op_node = create_node(NODE_BOOL_UN_OP, "!", 1, children_array);
            $$ = bool_un_op_node;
        }
    | NUMBER
        { $$ = $1; }
    | '(' RELATIONAL_EXPRESSION ')'
        { $$ = $2; }
    | IDENTIFIER
        { 
            ASTNode* id_node = create_node(NODE_IDENTIFIER, $1, 0, NULL);
            $$ = id_node;
        }
    ;

NUMBER
    : INT_LITERAL
        { 
            ASTNode* int_lit_node = create_node(NODE_INT_LITERAL, $1, 0, NULL);
            $$ = int_lit_node;
        }
    | FLOAT_LITERAL
        { 
            ASTNode* float_lit_node = create_node(NODE_FLOAT_LITERAL, $1, 0, NULL);
            $$ = float_lit_node;
        }
    ;

%%

/* C Code Section */

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

    printf("Parsing started...\n");
    if (yyparse() == 0) {
        printf("Parsing completed successfully.\n");
        printf("\nAbstract Syntax Tree (YAML):\n");

        print_ast_yaml(yaml_file, ast_root, 0);

        if (yaml_file != stdout)
            fclose(yaml_file);

        free_ast(ast_root);
    }

    return 0;
}
