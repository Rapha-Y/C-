#include "semantics.h"

int exp_rets_int(Syn_tree_node *node);

//remember to group errors, add lines and ids
void semantic_check(Syn_tree *tree) {
    int line;
    if((last_decl_main(tree) != 0) && (void_for_fun(tree) != 0) && (if_int_cond(tree) != 0)) {
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

    int in_first_child = 1;
    int in_next_sibling = 1;

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


int act_rets_int(Syn_tree_node *node) {
    //leave for later
    return 1;
}

int var_rets_int(Syn_tree_node *node) {
    Syn_tree_node *first_child = node->first_child;

    if(first_child->next_sibling == NULL) {
        return 1;
    } else {
        //missing out of bounds check
        return exp_rets_int(first_child->next_sibling->next_sibling);
    }
}

int fact_rets_int(Syn_tree_node *node) {
    Syn_tree_node *first_child = node->first_child;

    if(strcmp(node->first_child->str_value, "(") == 0) {
        return exp_rets_int(node->first_child->next_sibling);
    } else if(strcmp(node->first_child->str_value, "var") == 0) {
        return var_rets_int(node->first_child);
    } else if(strcmp(node->first_child->str_value, "activation") == 0) {
        return act_rets_int(node->first_child);
    } else { //num case
        return 1;
    }
}

int term_rets_int(Syn_tree_node *node) {
    Syn_tree_node *first_child = node->first_child;
    Syn_tree_node *last_child = node->first_child;

    while(last_child->next_sibling != NULL) {
        last_child = last_child->next_sibling;
    }

    int fc_ret_val = 0;
    int lc_ret_val = 0;

    if(first_child == last_child) {
        fc_ret_val = fact_rets_int(first_child);
        lc_ret_val = 1;
    } else {
        fc_ret_val = term_rets_int(first_child);
        lc_ret_val = fact_rets_int(last_child);
    }

    return (fc_ret_val && lc_ret_val);
}

int sum_exp_rets_int(Syn_tree_node *node) {
    Syn_tree_node *first_child = node->first_child;
    Syn_tree_node *last_child = node->first_child;

    while(last_child->next_sibling != NULL) {
        last_child = last_child->next_sibling;
    }

    int fc_ret_val = 0;
    int lc_ret_val = 0;

    if(first_child == last_child) {
        fc_ret_val = term_rets_int(first_child);
        lc_ret_val = 1;
    } else {
        fc_ret_val = sum_exp_rets_int(first_child);
        lc_ret_val = term_rets_int(last_child);
    }

    return (fc_ret_val && lc_ret_val);
}

int simp_exp_rets_int(Syn_tree_node *node) {
    Syn_tree_node *first_child = node->first_child;
    Syn_tree_node *last_child = node->first_child;

    while(last_child->next_sibling != NULL) {
        last_child = last_child->next_sibling;
    }

    int fc_ret_val = 0;
    int lc_ret_val = 0;

    fc_ret_val = sum_exp_rets_int(first_child);
    if(first_child == last_child) {
        lc_ret_val = 1;
    } else {
        lc_ret_val = sum_exp_rets_int(last_child);
    }

    return (fc_ret_val && lc_ret_val);
}

int exp_rets_int(Syn_tree_node *node) {
    Syn_tree_node *first_child = node->first_child;
    Syn_tree_node *last_child = node->first_child;

    while(last_child->next_sibling != NULL) {
        last_child = last_child->next_sibling;
    }

    if(first_child == last_child) {
        return sum_exp_rets_int(first_child);
    } else {
        return 0;
    }
}

int if_int_cond_runner(Syn_tree_node *node) {
    if(node->str_value && (strcmp(node->str_value, "selection-decl") == 0)) {
        int ret_val = exp_rets_int(node->first_child->next_sibling->next_sibling);
        if(ret_val == 0) {
            printf("ERRO SEMÂNTICO: CONDIÇÃO DE IF NÃO RETORNA VALOR INTEIRO\n");
        }
        return ret_val;
    }

    int in_first_child = 1;
    int in_next_sibling = 1;

    if(node->first_child != NULL) {
        in_first_child = if_int_cond_runner(node->first_child);
    }
    if(node->next_sibling != NULL) {
        in_next_sibling = if_int_cond_runner(node->next_sibling);
    }

    return (in_first_child && in_next_sibling);
}

int if_int_cond(Syn_tree *tree) {
    return if_int_cond_runner(tree->root);
}