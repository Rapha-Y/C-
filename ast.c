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

AST_node *new_AST_node_decl(int data_type, Token **names, int names_count) {
    AST_node_decl *node = malloc(sizeof(AST_node_decl));

    node->type = DECL_NODE;
    node->data_type = data_type;
    node->names = names;
    node->names_count = names_count;

    return (struct AST_node*)node;
}

AST_node *new_AST_const_node(int const_type, Value val) {
    AST_node_const *node = malloc(sizeof(AST_node_const));

    node->type = CONST_NODE;
    node->const_type = const_type;
    node->val = val;

    return (struct AST_node*)node;
}

AST_node *new_AST_if_node(AST_node *condition, AST_node *if_branch, AST_node **elif_branches, int elif_count, AST_node *else_branch) {
    AST_node_if *node = malloc(sizeof(AST_node_if));
    
    node->type = IF_NODE;
    node->condition = condition;
    node->if_branch = if_branch;
    node->elif_branches = elif_branches;
    node->elif_count = elif_count;
    node->else_branch = else_branch;

    return (struct AST_node*)node;
}

AST_node *new_AST_elif_node(AST_node *condition, AST_node *elif_branch) {
    AST_node_elif *node = malloc(sizeof(AST_node_elif));

    node->type = ELIF_NODE;
    node->condition = condition;
    node->elif_branch = elif_branch;

    return (struct AST_node*)node;
}

AST_node *new_AST_while_node(AST_node, *condition, AST_node *while_branch) {
    AST_node_while *node = malloc(sizeof(AST_node_while));

    node->type = WHILE_NODE;
    node->condition = condition;
    node->while_branch = while_branch;

    return (struct AST_node*)node;
}

AST_node *new_AST_assign_node(Token *entry, AST_node *assign_val) {
    AST_node_assign *node = malloc(sizeof(AST_node_assign));

    node->type = ASSIGN_NODE;
    node->entry = entry;
    node->assign_val = assign_val;

    return (struct AST_node*)node;
}

AST_node *new_AST_main_node(int statement_type) {
    AST_node_main *node = malloc(sizeof(AST_node_main));

    node->type = MAIN_NODE;
    node->statement_type = statement_type;

    return (struct AST_node*)node;
}

AST_node *new_AST_fun_call_node(Token *entry, AST_node **params, int param_num) {
    AST_node_fun_call *node = malloc(sizeof(AST_node_fun_call));

    node->type = FUN_CALL;
    node->entry = entry;
    node->params = params;
    node->param_num = param_num;

    return (struct AST_node*)node;
}

AST_node *new_AST_math_node(enum Math_op op, AST_node *left, AST_node *right) {
    AST_node_math *node = malloc(sizeof(AST_node_math));

    node->type = MATH_NODE;
    node->op = op;
    node->left = left;
    node->right = right;

    return (struct AST_node*)node;
}

AST_node *new_AST_comp_node(enum Comp_op op, AST_node *left, AST_node *right) {
    AST_node_comp *node = malloc(sizeof(AST_node_comp));

    node->type = COMP_NODE;
    node->op = op;
    node->left = left;
    node->right = right;

    return (struct AST_node*)node;
}

AST_node *new_AST_fun_decl_node(int ret_type, Token *entry) {
    AST_node_fun_decl *node = malloc(sizeof(AST_node_fun_decl));

    node->type = FUN_DECL;
    node->ret_type = ret_type;
    node->entry = entry;

    return (struct AST_node*)node;
}

AST_node *new_AST_ret_node(int ret_type, AST_node *ret_val) {
    AST_node_ret *node = malloc(sizeof(AST_node_ret));

    node->type = RET_NODE;
    node->ret_type = ret_type;
    node->ret_val = ret_val;

    return (struct AST_node*)node;
}

void AST_print_node(AST_node *node) {
    AST_node_decl *temp_decl;
    AST_node_const *temp_const;
    AST_node_if *temp_if;
    AST_node_assign *temp_assign;
    AST_node_main *temp_main;
    AST_node_fun_call *temp_fun_call;
    AST_node_math *temp_math;
    AST_node_comp *temp_comp;
    AST_node_fun_decl *temp_fun_decl;
    AST_node_ret *temp_ret;

    switch(node->type) {
        case BASIC_NODE:
            printf("Basic node\n");
            break;
        case DECL_NODE:
            temp_decl = (struct AST_node_decl*)node;
            printf("Declaration node of data type %d for %d names\n", temp_decl->data_type, temp_decl->names_count);
            break;
        case CONST_NODE:
            temp_const = (struct AST_node_const*)node;
            printf("Constant node of const type %d\n", temp_const->const_type);
            break;
        case IF_NODE:
            temp_if = (struct AST_node_if*)node;
            printf("If node with %d elifs\n", temp_if->elif_count);
            break;
        case ELIF_NODE:
            printf("Elif node\n");
            break;
        case WHILE_NODE:
            printf("While node\n");
            break;
        case ASSIGN_NODE:
            temp_assign = (struct AST_node_assign*)node;
            printf("Assign node of entry %s\n", temp_assign->entry->name);
            break;
        case MAIN_NODE:
            temp_assign = (struct AST_node_main*)node;
            printf("Main node of statement %d\n", temp_assign->statement_type);
            break;
        case FUN_CALL:
            temp_fun_call = (struct AST_node_fun_call*)node;
            printf("Function call node with %d parameters\n", temp_fun_call->param_num);
            break;
        case MATH_NODE:
            temp_math = (struct AST_node_math*)node;
            printf("Arithmetic node of operator %d\n", temp_math->op);
            break;
        case COMP_NODE:
            temp_comp = (struct AST_node_comp*)node;
            printf("Comparation node of operator %d\n", temp_comp->op);
            break;
        case FUN_DECL:
            temp_fun_decl = (struct AST_node_fun_decl*)node;
            printf("Function declaration node of %s with ret_type %d\n", temp_fun_decl->entry->name, temp_fun_decl->ret_type);
            break;
        case RET_NODE:
            temp_ret = (struct AST_node_ret*)node;
            printf("Return node of ret_type %d\n", temp_ret->ret_type);
            break;
        default:
            fprintf(stderr, "Error in node selection!\n");
            exit(1);
    }
}

void AST_traversal(AST_node *node) {
    if(node == NULL) {
        return;
    }

    if(node->type == BASIC_NODE || node->type == MATH_NODE || node->type == COMP_NODE) {
        AST_traversal(node->left);
        AST_traversal(node->right);
        AST_print_node(node);
    } else if(node->type == IF_NODE) {
        AST_node_if *temp_if = (struct AST_node_if*)node;
        AST_traversal(temp_if->condition);
        AST_traversal(temp_if->if_branch);
        for(int i = 0; i < temp_if->elif_count; i++) {
            AST_traversal(temp_if->elif_branches[i]);
        }
        AST_traversal(temp_if->else_branch);
        AST_print_node(node);
    } else if(node->type == ELIF_NODE) {
        AST_node_elif *temp_elif = (struct AST_node_elif*)node;
        AST_traversal(temp_elif->condition);
        AST_traversal(temp_elif->elif_branch);
        AST_print_node(node);
    } else if(node->type == WHILE_NODE) {
        AST_node_while *temp_while = (struct AST_node_while*)node;
        AST_traversal(temp_while->condition);
        AST_traversal(temp_while->while_branch);
        AST_print_node(node);
    } else if(node->type == ASSIGN_NODE) {
        AST_node_assign *temp_assign = (struct AST_node_assign*)node;
        AST_traversal(temp_assign->assign_val);
        AST_print_node(node);
    } else if(node->type == FUN_CALL) {
        AST_node_fun_call *temp_fun_call = (struct AST_node_fun_call*)node;
        for(int i = 0; i < temp_fun_call->param_num; i++) {
            AST_traversal(temp_fun_call->params[i]);
        }
        AST_print_node(node);
    } else if(node->type == RET_NODE) {
        AST_node_ret *temp_ret = (struct AST_node_ret*)node;
        AST_traversal(temp_ret->ret_val);
        AST_print_node(node);
    } else {
        AST_print_node(node);
    }
}