/* ast.c */
#include "ast.h"

ASTNode* create_node(NodeType type, char* value, int num_children, ASTNode** children_array) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for ASTNode.\n");
        exit(1);
    }
    node->type = type;
    node->value = value ? strdup(value) : NULL;
    node->num_children = num_children;

    if (num_children > 0) {
        node->children = (ASTNode**)malloc(sizeof(ASTNode*) * num_children);
        if (node->children == NULL) {
            fprintf(stderr, "Error: Memory allocation failed for ASTNode children.\n");
            exit(1);
        }
        memcpy(node->children, children_array, sizeof(ASTNode*) * num_children);
    } else {
        node->children = NULL;
    }

    return node;
}

const char* node_type_to_string(NodeType type) {
    switch (type) {
        case NODE_BLOCK:              return "Block";
        case NODE_STATEMENT_LIST:     return "StatementList";
        case NODE_DECLARATION:        return "Declaration";
        case NODE_ASSIGNMENT:         return "Assignment";
        case NODE_PRINT:              return "Print";
        case NODE_SCANF:              return "Scanf";           /* Added this line */
        case NODE_IF_STATEMENT:       return "IfStatement";
        case NODE_WHILE_STATEMENT:    return "WhileStatement";
        case NODE_RETURN_STATEMENT:   return "ReturnStatement";
        case NODE_FUNCTION_CALL:      return "FunctionCall";
        case NODE_FUNCTION_DECLARATION:return "FunctionDeclaration";
        case NODE_FUNCTION_LIST:      return "FunctionList";
        case NODE_PARAMETER_LIST:     return "ParameterList";
        case NODE_PARAMETER:          return "Parameter";
        case NODE_ARGUMENT_LIST:      return "ArgumentList";
        case NODE_VARIABLE_LIST:      return "VariableList";    /* Added this line */
        case NODE_BIN_OP:             return "BinOp";
        case NODE_UN_OP:              return "UnOp";
        case NODE_BOOL_BIN_OP:        return "BoolBinOp";
        case NODE_BOOL_UN_OP:         return "BoolUnOp";
        case NODE_REL_OP:             return "RelOp";
        case NODE_TYPE:               return "Type";
        case NODE_ARRAY_TYPE:         return "ArrayType";
        case NODE_ARRAY_SPECIFIER:    return "ArraySpecifier";
        case NODE_INDEXED_IDENTIFIER: return "IndexedIdentifier";
        case NODE_IDENTIFIER:         return "Identifier";
        case NODE_INT_LITERAL:        return "IntLiteral";
        case NODE_FLOAT_LITERAL:      return "FloatLiteral";
        case NODE_TYPE_CAST:          return "TypeCast";
        case NODE_STRING_LITERAL:     return "StringLiteral";
        case NODE_EXPRESSION_LIST:    return "ExpressionList";
        default:                      return "Unknown";
    }
}

void escape_yaml_string(FILE* file, const char* str) {
    for (const char* p = str; *p; p++) {
        if (*p == '\\' || *p == '"' || *p == '\n') {
            fputc('\\', file);
            if (*p == '\n') {
                fputc('n', file);
            } else {
                fputc(*p, file);
            }
        } else {
            fputc(*p, file);
        }
    }
}

void print_ast_yaml(FILE* file, ASTNode* node, int indent) {
    if (node == NULL)
        return;

    /* Print indentation */
    for (int i = 0; i < indent; i++)
        fprintf(file, "  ");

    /* Print node type */
    fprintf(file, "- type: %s\n", node_type_to_string(node->type));

    /* Print node value if it exists */
    if (node->value != NULL) {
        for (int i = 0; i < indent + 1; i++)
            fprintf(file, "  ");
        fprintf(file, "value: ");

        /* Enclose all values in double quotes */
        fputc('"', file);

        if (node->type == NODE_STRING_LITERAL) {
            /* For StringLiteral nodes, print the value as-is */
            fprintf(file, "%s", node->value);
        } else {
            /* For other nodes, escape special characters */
            escape_yaml_string(file, node->value);
        }

        fputc('"', file);
        fprintf(file, "\n");
    }

    /* Print children if they exist */
    if (node->num_children > 0) {
        for (int i = 0; i < indent + 1; i++)
            fprintf(file, "  ");
        fprintf(file, "children:\n");

        for (int i = 0; i < node->num_children; i++) {
            print_ast_yaml(file, node->children[i], indent + 2);
        }
    }
}

void free_ast(ASTNode* node) {
    if (node == NULL)
        return;

    for (int i = 0; i < node->num_children; i++) {
        free_ast(node->children[i]);
    }

    if (node->children != NULL)
        free(node->children);

    if (node->value != NULL)
        free(node->value);

    free(node);
}
