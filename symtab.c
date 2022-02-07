#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "symtab.h"
#define FILESIZE 216
#define SHIFT 4

void buildSymTabSubTree(Syn_tree_node *node, char *scope);
static SymItem hashTable[FILESIZE];

static int generateHashCode(char* name, char* scope) { 
    int aux = 0; int i = 0;
    
    while (name[i] != '\0') { 
        aux = ((aux << SHIFT) + name[i]) % FILESIZE;
        i++;
    }
    i = 0;
    
    while (scope[i] != '\0') { 
        aux = ((aux << SHIFT) + scope[i]) % FILESIZE;
        i++;
    }
    
    return aux;
}

bool isSameSymbol(char *name, char* itemName, char *scope, char *itemScope) {
    return strcmp(name, itemName) == 0 && (strcmp(scope, itemScope) == 0);
}

void printSymTab(FILE *listing) {
    int i;
    
    fprintf(listing," Nome          Escopo              Tipo                Linha    \n");
    fprintf(listing,"--------------------------------------------------------------------\n");
    for (i=0; i<FILESIZE; i++) {
        if (hashTable[i] != NULL) {
            SymItem item = hashTable[i];
            while (item != NULL) {
                fprintf(listing, "%-12s  ", item->name);
		        fprintf(listing, "%-12s  ", item->scope);
		        fprintf(listing, "%-8s  ", item->declarationType);	
                fprintf(listing, "%-8s  ", item->type);

                Line line = item->lines;
                while (line != NULL) { 
                    fprintf(listing, "%3d ", line->lineNum);
                    line = line->next;
                }
                fprintf(listing, "\n");
                item = item->next;
            }
        }
    }
}

void updateLineOnItem(SymItem item, int lineNum) {
    Line line = item->lines;
    while (line->next != NULL) {
        line = line->next;
    }
    line->next = (Line) malloc(sizeof(struct Line));
    line->next->lineNum = lineNum;
    line->next->next = NULL;          
}

void insertSymTab(char *name, char *scope, char *dType, char *type, int lineNum) {
    int hashCode = generateHashCode(name, scope);
    SymItem item = hashTable[hashCode];

    while ((item != NULL) && !isSameSymbol(name, item->name, scope, item->scope)) {
        item = item->next;
    } 
    
    if (item == NULL || (strcmp(scope, item->scope) != 0)) { 
        SymItem newItem = (SymItem) malloc(sizeof(struct SymItem));
        newItem->lines = (Line) malloc(sizeof(struct Line));
        newItem->lines->lineNum = lineNum;
        newItem->lines->next = NULL;
        newItem->name = name;
        newItem->scope = scope;
        newItem->declarationType = dType;
        newItem->type = type;
        newItem->next = hashTable[hashCode];
        hashTable[hashCode] = newItem; 
    } else {
        updateLineOnItem(item, lineNum);
    }
}

void updateNodeItemOnTable(Syn_tree_node *node, bool isFunction, char *scope) {
    char *itemName = ""; 
    char *itemScope = scope; 
    int line;
    Syn_tree_node *child = node->first_child;
    
    if (isFunction) {
        itemName = child->str_value;
        line = child->line;
        itemScope = "global";
    } else if (strcmp(child->str_value, "ID") == 0) {
        itemName = child->first_child->str_value;
        line = child->first_child->line;
    }
    //printf("Update item line: %s\n", itemName);

    int hashCode = generateHashCode(itemName, itemScope);
    SymItem item = hashTable[hashCode];

    if (item != NULL) {
        updateLineOnItem(item, line);
    }

    if (node->first_child != NULL) {
        buildSymTabSubTree(node->first_child, scope);
    }
    if (node->next_sibling != NULL) {
        buildSymTabSubTree(node->next_sibling, scope);
    }
}
 
void insertNodeOnTable(Syn_tree_node *node, bool isFunction, char *scope, char *declarationType) {
    Syn_tree_node *child = node->first_child;
    char *itemType = ""; char *itemName = ""; 
    int line; 
    
    while (child != NULL) {
        if (strcmp(child->str_value, "type-specifier") == 0 && child->child_num == 1) {
            itemType = child->first_child->str_value;
        }
        if (strcmp(child->str_value, "ID") == 0 && child->child_num == 1) {
            itemName = child->first_child->str_value;
            line = child->first_child->line;
        }
        child = child->next_sibling;
    }
    insertSymTab(itemName, scope, declarationType, itemType, line);
    
    if (isFunction) {
        buildSymTabSubTree(node->first_child, itemName);
    }
}

void buildSymTabSubTree(Syn_tree_node *node, char *scope) {
    if (node != NULL && node->str_value != NULL) {
        //printf("Nó atual: %s\n", node->str_value);

        if (strcmp(node->str_value, "var-declaration") == 0) {
            insertNodeOnTable(node, false, scope, "variable ");
        } else if (strcmp(node->str_value, "var") == 0) {    
            updateNodeItemOnTable(node, false, scope);
        } else if (strcmp(node->str_value, "fun-declaration") == 0) {
            insertNodeOnTable(node, true, scope, "function ");
        } else if (strcmp(node->str_value, "activation") == 0) {
            updateNodeItemOnTable(node, true, scope);
        } else if (strcmp(node->str_value, "param") == 0) {
            insertNodeOnTable(node, false, scope, "parameter");
        } else {
            if (node->first_child != NULL) {
                buildSymTabSubTree(node->first_child, scope);
            }
            if (node->next_sibling != NULL) {
                buildSymTabSubTree(node->next_sibling, scope);
            }
        }
    }
}

void buildSymTab(Syn_tree *tree) {
    buildSymTabSubTree(tree->root, "global");
}