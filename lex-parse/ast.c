// ast.c
#include "ast.h"

// Function to create an AST node with variable children or an array of children
ASTNode* create_node(NodeType type, char* value, int num_children, ASTNode** children_array, ...) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value ? strdup(value) : NULL;
    node->num_children = num_children;

    if (num_children > 0) {
        node->children = (ASTNode**)malloc(sizeof(ASTNode*) * num_children);

        if (children_array != NULL) {
            // Use the provided array
            memcpy(node->children, children_array, sizeof(ASTNode*) * num_children);
        } else {
            // Use variable arguments
            va_list args;
            va_start(args, children_array);
            for (int i = 0; i < num_children; i++) {
                node->children[i] = va_arg(args, ASTNode*);
            }
            va_end(args);
        }
    } else {
        node->children = NULL;
    }

    return node;
}

// Helper function to convert NodeType to string
const char* node_type_to_string(NodeType type) {
    switch (type) {
        case NODE_BLOCK:         return "Block";
        case NODE_DECLARATION:   return "Declaration";
        case NODE_ASSIGNMENT:    return "Assignment";
        case NODE_PRINT:         return "Print";
        case NODE_BIN_OP:        return "BinOp";
        case NODE_UN_OP:         return "UnOp";
        case NODE_TYPE:          return "Type";
        case NODE_IDENTIFIER:    return "Identifier";
        case NODE_INT_LITERAL:   return "IntLiteral";
        case NODE_FLOAT_LITERAL: return "FloatLiteral";
        default:                 return "Unknown";
    }
}

// Function to print the AST in YAML format with proper indentation
void print_ast_yaml(FILE* file, ASTNode* node, int indent) {
    if (node == NULL)
        return;

    // Indentation for the current node
    for (int i = 0; i < indent; i++)
        fprintf(file, " ");

    // Start of a YAML mapping
    fprintf(file, "- type: %s\n", node_type_to_string(node->type));

    // If the node has a value, include it
    if (node->value != NULL) {
        for (int i = 0; i < indent + 2; i++)
            fprintf(file, " ");  // Indent under type
        fprintf(file, "value: \"%s\"\n", node->value);
    }

    // If the node has children, list them
    if (node->num_children > 0) {
        for (int i = 0; i < indent + 2; i++)
            fprintf(file, " ");  // Indent under type/value
        fprintf(file, "children:\n");

        for (int i = 0; i < node->num_children; i++) {
            // Recursively print each child with increased indentation
            print_ast_yaml(file, node->children[i], indent + 4);
        }
    }
}

// Function to print the AST in a human-readable format
void print_ast(ASTNode* node, int indent) {
    if (node == NULL)
        return;

    for (int i = 0; i < indent; i++)
        printf("  ");

    // Print node information based on its type
    switch (node->type) {
        case NODE_BLOCK:
            printf("Block\n");
            break;
        case NODE_DECLARATION:
            printf("Declaration\n");
            break;
        case NODE_ASSIGNMENT:
            printf("Assignment\n");
            break;
        case NODE_PRINT:
            printf("Print\n");
            break;
        case NODE_BIN_OP:
            printf("BinOp: %s\n", node->value);
            break;
        case NODE_UN_OP:
            printf("UnOp: %s\n", node->value);
            break;
        case NODE_TYPE:
            printf("Type: %s\n", node->value);
            break;
        case NODE_IDENTIFIER:
            printf("Identifier: %s\n", node->value);
            break;
        case NODE_INT_LITERAL:
            printf("IntLiteral: %s\n", node->value);
            break;
        case NODE_FLOAT_LITERAL:
            printf("FloatLiteral: %s\n", node->value);
            break;
        default:
            printf("Unknown Node\n");
    }

    // Recursively print child nodes
    for (int i = 0; i < node->num_children; i++) {
        print_ast(node->children[i], indent + 1);
    }
}

// Function to free the AST
void free_ast(ASTNode* node) {
    if (node == NULL)
        return;

    // Free child nodes
    for (int i = 0; i < node->num_children; i++) {
        free_ast(node->children[i]);
    }

    // Free the children array
    if (node->children != NULL)
        free(node->children);

    // Free the value string
    if (node->value != NULL)
        free(node->value);

    // Free the node itself
    free(node);
}
