#include <stdio.h>
#include <stdlib.h>
#include "syntree.h"

Syn_tree *syn_tree;

void init_syn_tree() {
    syn_tree = (Syn_tree*)malloc(sizeof(Syn_tree));
    syn_tree->root = NULL;
}

void insert_syn_tree(char *str_value, int int_value, int child_num, int line) {
    Syn_tree_node *new_node = (Syn_tree_node*)malloc(sizeof(Syn_tree_node));
    if(str_value == NULL) {
        new_node->str_value = NULL;
        new_node->int_value = int_value;
    } else {
        new_node->str_value = str_value;
        new_node->int_value = 0;
    }
    new_node->child_num = child_num;
    new_node->next_sibling = NULL;

    // árvore vazia
    if(syn_tree->root == NULL) {
        new_node->first_child = NULL;
        syn_tree->root = new_node;
        syn_tree->root_sibling_total = 1;
    } else {
        // nó folha
        if(child_num == 0) {
            new_node->first_child = NULL;
            Syn_tree_node *last_child = syn_tree->root;
            while(last_child->next_sibling != NULL) last_child = last_child->next_sibling;
            last_child->next_sibling = new_node;
            syn_tree->root_sibling_total++;
        } else {
            Syn_tree_node *node_to_change_siblings;
            Syn_tree_node *node_to_become_first_child = syn_tree->root;
            int unchanged_sibling_num = syn_tree->root_sibling_total - child_num;
            for(int i = 0; i < unchanged_sibling_num; i++) {
                node_to_change_siblings = node_to_become_first_child;
                node_to_become_first_child = node_to_become_first_child->next_sibling;
            }
            new_node->first_child = node_to_become_first_child;
            // todos os nós no nível raíz viram filhos
            if(unchanged_sibling_num == 0) {
                syn_tree->root = new_node;
            } else if (unchanged_sibling_num > 0) {
                node_to_change_siblings->next_sibling = new_node;
            } else {
                printf("Insertion error at line %d for %s or %d with child num %d\n", line, str_value, int_value, child_num);
                exit(1);
            }
            syn_tree->root_sibling_total = syn_tree->root_sibling_total - child_num + 1;
        }
    }
}

void print_subtree(Syn_tree_node *node, int tab_num) {
    for(int i = 0; i < tab_num; i++) {
        printf(" ");
    }
    if(node->str_value == NULL) {
        printf("%d", node->int_value);
    } else {
        printf("%s", node->str_value);
    }
    printf(" (%d children)\n", node->child_num);
    
    if(node->first_child != NULL) {
        print_subtree(node->first_child, tab_num + 1);
    }

    if(node->next_sibling != NULL) {
        print_subtree(node->next_sibling, tab_num);
    }
}

void print_tree() {
    print_subtree(syn_tree->root, 0);
}