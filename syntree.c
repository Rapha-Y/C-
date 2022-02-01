#include <stdio.h>
#include <stdlib.h>
#include "syntree.h"

Syn_tree *syn_tree;

void init_syn_tree() {
    syn_tree = (Syn_tree*)malloc(sizeof(Syn_tree));
    syn_tree->root = NULL;
}

void insert_syn_tree(char *value, int child_num) {
    Syn_tree_node *new_node = (Syn_tree_node*)malloc(sizeof(Syn_tree_node));
    new_node->value = value;
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
            } else {
                node_to_change_siblings->next_sibling = new_node;
            }
            syn_tree->root_sibling_total = syn_tree->root_sibling_total - child_num + 1;
        }
    }
}

void print_subtree(Syn_tree_node *node, int tab_num) {
    for(int i = 0; i < tab_num; i++) {
        printf("\t");
    }
    printf("%s\n", node->value);
    
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