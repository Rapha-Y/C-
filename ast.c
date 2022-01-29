#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AST_node *new_AST_node(Node_type type, AST_node *left, AST_node *right) {
    AST_node *node = malloc(sizeof(AST_node));

    node->type = type;
    node->left = left;
    node->right = right;
    
    return node;
}

AST_node *new_AST_node_decl(int data_type, Token **names) {
    AST_node_decl *node = malloc(sizeof(AST_node_decl));

    node->type = DECL_NODE;
    node->data_type = data_type;
    node->names = names;

    return (struct AST_node*)node;
}

AST_node *new_AST_const_node(int const_type, Value val) {
    AST_node_const *node = malloc(sizeof(AST_node_const));

    node->type = CONST_NODE;
    node->const_type = const_type;
    node->val = val;

    return (struct AST_node*)node;
}