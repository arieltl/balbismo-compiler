%{
#include <stdio.h>
#include "ast.h"

void yyerror(const char *s);
extern int yylex();
ASTNode* ast_root;  // Root of the AST
%}

%code requires {
    #include "ast.h"
}

%union {
    char* str;
    ASTNode* ast;
    struct {
        int num;
        ASTNode** nodes;
    } stmt_list;
}

/* Token Definitions */
%token <str> IDENTIFIER
%token <str> INT FLOAT PRINTF
%token <str> INT_LITERAL FLOAT_LITERAL

%type <ast> PROGRAM BLOCK STATEMENT DECLARATION ASSIGNMENT PRINT
%type <ast> EXPRESSION TERM FACTOR
%type <str> TYPES
%type <stmt_list> STATEMENT_LIST

/* Operator Precedence */
%left '+' '-'
%left '*' '/'

%%

PROGRAM
    : BLOCK                { ast_root = $1; }
    ;

BLOCK
    : '{' '}' { $$ = create_node(NODE_BLOCK, NULL, 0, NULL); }
    | '{' STATEMENT_LIST '}' {
        $$ = create_node(NODE_BLOCK, NULL, $2.num, $2.nodes);
      }
    ;

STATEMENT_LIST
    : STATEMENT
      {
        $$.num = 1;
        $$.nodes = (ASTNode**)malloc(sizeof(ASTNode*));
        $$.nodes[0] = $1;
      }
    | STATEMENT_LIST STATEMENT
      {
        $$.num = $1.num + 1;
        $$.nodes = (ASTNode**)malloc($$.num * sizeof(ASTNode*));

        // Copy existing nodes from $1 to $$
        memcpy($$.nodes, $1.nodes, $1.num * sizeof(ASTNode*));

        // Append $2 to the list
        $$.nodes[$$.num - 1] = $2;

        // Free the old list in $1
        free($1.nodes);
      }
    ;

STATEMENT
    : DECLARATION ';'      { $$ = $1; }
    | ASSIGNMENT ';'       { $$ = $1; }
    | PRINT ';'            { $$ = $1; }
    ;

DECLARATION
    : TYPES IDENTIFIER
        {
            $$ = create_node(NODE_DECLARATION, NULL, 2, NULL,
                             create_node(NODE_TYPE, $1, 0, NULL),
                             create_node(NODE_IDENTIFIER, $2, 0, NULL));
        }
    | TYPES IDENTIFIER '=' EXPRESSION
        {
            $$ = create_node(NODE_DECLARATION, NULL, 3, NULL,
                             create_node(NODE_TYPE, $1, 0, NULL),
                             create_node(NODE_IDENTIFIER, $2, 0, NULL),
                             $4);
        }
    ;

ASSIGNMENT
    : IDENTIFIER '=' EXPRESSION
        {
            $$ = create_node(NODE_ASSIGNMENT, NULL, 2, NULL,
                             create_node(NODE_IDENTIFIER, $1, 0, NULL), $3);
        }
    ;

PRINT
    : PRINTF '(' EXPRESSION ')'
        {
            $$ = create_node(NODE_PRINT, NULL, 1, NULL, $3);
        }
    ;

TYPES
    : INT                  { $$ = $1; }
    | FLOAT                { $$ = $1; }
    ;

EXPRESSION
    : TERM
        { $$ = $1; }
    | EXPRESSION '+' TERM
        {
            $$ = create_node(NODE_BIN_OP, "+", 2, NULL, $1, $3);
        }
    | EXPRESSION '-' TERM
        {
            $$ = create_node(NODE_BIN_OP, "-", 2, NULL, $1, $3);
        }
    ;

TERM
    : FACTOR
        { $$ = $1; }
    | TERM '*' FACTOR
        {
            $$ = create_node(NODE_BIN_OP, "*", 2, NULL, $1, $3);
        }
    | TERM '/' FACTOR
        {
            $$ = create_node(NODE_BIN_OP, "/", 2, NULL, $1, $3);
        }
    ;

FACTOR
    : '(' EXPRESSION ')'
        { $$ = $2; }
    | INT_LITERAL
        { $$ = create_node(NODE_INT_LITERAL, $1, 0, NULL); }
    | FLOAT_LITERAL
        { $$ = create_node(NODE_FLOAT_LITERAL, $1, 0, NULL); }
    | IDENTIFIER
        { $$ = create_node(NODE_IDENTIFIER, $1, 0, NULL); }
    | '+' FACTOR
        {
            $$ = create_node(NODE_UN_OP, "+", 1, NULL, $2);
        }
    | '-' FACTOR
        {
            $$ = create_node(NODE_UN_OP, "-", 1, NULL, $2);
        }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char** argv) {
    FILE* yaml_file = NULL;

    // Check if a filename is provided as an argument for YAML output
    if (argc > 2 && strcmp(argv[1], "-o") == 0) {
        yaml_file = fopen(argv[2], "w");
        if (yaml_file == NULL) {
            fprintf(stderr, "Error: Cannot open output file %s\n", argv[2]);
            return 1;
        }
    } else {
        // Default to stdout if no file is specified
        yaml_file = stdout;
    }

    printf("Parsing started...\n");
    if (yyparse() == 0) {
        printf("Parsing completed successfully.\n");
        printf("\nAbstract Syntax Tree (YAML):\n");

        // Print AST in YAML format to the specified file
        print_ast_yaml(yaml_file, ast_root, 0);

        // Close the file if it's not stdout
        if (yaml_file != stdout)
            fclose(yaml_file);

        // Free the AST to prevent memory leaks
        free_ast(ast_root);
    }

    return 0;
}
