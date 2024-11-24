// ast.h
#ifndef AST_H
#define AST_H

#include <stdio.h>     // Include stdio.h to define FILE
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Enumeration of all possible node types in the AST
typedef enum {
    NODE_BLOCK,
    NODE_DECLARATION,
    NODE_ASSIGNMENT,
    NODE_PRINT,
    NODE_BIN_OP,
    NODE_UN_OP,
    NODE_TYPE,
    NODE_IDENTIFIER,
    NODE_INT_LITERAL,
    NODE_FLOAT_LITERAL
} NodeType;

// Structure representing an AST node
typedef struct ASTNode {
    NodeType type;
    char* value;                 // For identifiers, literals, and operator symbols
    int num_children;
    struct ASTNode** children;   // Dynamic array of child nodes
} ASTNode;

// Function prototypes
ASTNode* create_node(NodeType type, char* value, int num_children, ASTNode** children_array, ...);
void print_ast(ASTNode* node, int indent);
void print_ast_yaml(FILE* file, ASTNode* node, int indent);
void free_ast(ASTNode* node);

#endif // AST_H
