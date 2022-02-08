#include "semantics.h"

//remember to group errors, add lines and ids
void semantic_check(Syn_tree *tree) {
    int line;
    if(!last_decl_main(tree)) {
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