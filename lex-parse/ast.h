// ast.h
#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NODE_BLOCK,
    NODE_STATEMENT_LIST,
    NODE_DECLARATION,
    NODE_ASSIGNMENT,
    NODE_PRINT,
    NODE_IF_STATEMENT,
    NODE_BIN_OP,
    NODE_UN_OP,
    NODE_BOOL_BIN_OP,
    NODE_BOOL_UN_OP,
    NODE_REL_OP,
    NODE_TYPE,
    NODE_IDENTIFIER,
    NODE_INT_LITERAL,
    NODE_FLOAT_LITERAL
} NodeType;

typedef struct ASTNode {
    NodeType type;
    char* value;                 // For identifiers, literals, and operator symbols
    int num_children;
    struct ASTNode** children;   // Dynamic array of child nodes
} ASTNode;

// Function to create an AST node
ASTNode* create_node(NodeType type, char* value, int num_children, ASTNode** children_array);

// Function to print the AST in YAML format
void print_ast_yaml(FILE* file, ASTNode* node, int indent);

// Function to free the AST
void free_ast(ASTNode* node);

// Function to convert node types to string
const char* node_type_to_string(NodeType type);

#endif // AST_H
