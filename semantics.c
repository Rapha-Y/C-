#include "semantics.h"

//remember to group errors, add lines and ids
void semantic_check(Syn_tree *tree) {
    int line;
    if((last_decl_main(tree) != 0) && (void_for_fun(tree) != 0)) {
        exit(1);
    }
}

int last_decl_main(Syn_tree *tree) {
    Syn_tree_node *last_decl = tree->root->first_child->first_child->next_sibling;

    if(strcmp(last_decl->first_child->str_value, "fun-declaration") != 0) {
        printf("ERRO SEMÂNTICO: ÚLTIMA DECLARAÇÃO NÃO É DE FUNÇÃO\n");
        return 0;
    } else {
        Syn_tree_node *type_spec = last_decl->first_child->first_child;

        if(strcmp(type_spec->first_child->str_value, "void") != 0) {
            printf("ERRO SEMÂNTICO: ÚLTIMA DECLARAÇÃO DE FUNÇÃO NÃO É DO TIPO VOID\n");
            return 0;
        }

        Syn_tree_node *id_val = type_spec->next_sibling->first_child;

        if(strcmp(id_val->str_value, "main") != 0) {
            printf("ERRO SEMÂNTICO: ÚLTIMA DECLARAÇÃO DE FUNÇÃO NÃO É MAIN\n");
            return 0;
        }
    }

    return 1;
}

int void_for_fun_runner(Syn_tree_node *node) {
    if(strcmp(node->str_value, "var-declaration") == 0) {
        if(strcmp(node->first_child->first_child->str_value, "void") == 0) {
            printf("ERRO SEMÂNTICO: VARIÁVEL DECLARADA COM TIPO VOID\n");
            return 0;
        }
    } else if(strcmp(node->str_value, "param") == 0) {
        if(strcmp(node->first_child->first_child->str_value, "void") == 0) {
            printf("ERRO SEMÂNTICO: PARÂMETRO DECLARADO COM TIPO VOID\n");
            return 0;
        }
    }

    int in_first_child = 0;
    int in_next_sibling = 0;

    if((node->first_child != NULL) && (node->first_child->str_value != NULL)) {
        void_for_fun_runner(node->first_child);
    }
    if((node->next_sibling != NULL) && (node->next_sibling->str_value != NULL)) {
        void_for_fun_runner(node->next_sibling);
    }

    return (in_first_child || in_next_sibling);
}

int void_for_fun(Syn_tree *tree) {
    return void_for_fun_runner(tree->root);
}