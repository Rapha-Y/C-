#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

// create hash table
void init_table() {
    h_table = malloc(SIZE * sizeof(Token*));
    for(int i = 0; i < SIZE; i++) h_table[i] = NULL;
}

unsigned int hash(char *key) {
    unsigned int h_val = 0;
    for(; *key != '\0'; key++) h_val += *key;
    h_val += key[0] % 11 + (key[0] << 3) - key[0];
    return h_val % SIZE;
}

void insert_token(char *name, int len, int type, int line) {
    unsigned int h_val = hash(name);
    Token *token = h_table[h_val];

    while((token != NULL) && (strcmp(name, token->name) != 0)) token = token->next;

    if (token == NULL) {
        token = (Token*) malloc(sizeof(Token));
        strncpy(token->name, name, len);
        token->type = type;
        token->first = (Occur*) malloc(sizeof(Occur));
        token->first->line = line;
        token->first->next = NULL;
        token->next = h_table[h_val];
        h_table[h_val] = token;
        printf("Inserted %s for the first time with line number %d!\n", name, line);
    } else {
        Occur *occur = token->first;
        while(occur->next != NULL) occur = occur->next;
        occur->next = (Occur*) malloc(sizeof(Occur));
        occur->next->line = line;
        occur->next->next = NULL;
        printf("Found %s again at line %d!\n", name, line);
    }
}

Token *search_token(char *name) {
    unsigned int h_val = hash(name);
    Token *token = h_table[h_val];
    while((token != NULL) && (strcmp(name, token->name) != 0)) token = token->next;
    return token;
}

void symtab_dump(FILE *of) {
    fprintf(of, "------------ ------ ------------\n");
    fprintf(of, "Name         Type   Line Numbers\n");
    fprintf(of, "------------ ------ -------------\n");
    for (int i = 0; i < SIZE; ++i) {
        if (h_table[i] != NULL) {
            Token *token = h_table[i];
            while(token != NULL) {
                Occur *occur = token->first;
                fprintf(of,"%-12s ", token->name);
                if(token->type == INT_TYPE) fprintf(of, "%-7s","int");
                else if(token->type == ARRAY_TYPE) fprintf(of, "array of int");
                else if(token->type == FUNCTION_TYPE) {
                    fprintf(of, "function returns ");
                    if(token->ret_type == VOID_TYPE) fprintf(of, "%-7s","nothing");
                    else if(token->ret_type == INT_TYPE) fprintf(of, "%-7s","int");
                    else fprintf(of, "%-7s","undef");              
                } else fprintf(of,"%-7s","undef");
                while(occur != NULL) {
                    fprintf(of, "%4d ", occur->line);
                    occur = occur->next;
                }
                fprintf(of, "\n");
			    token = token->next;
            }
        }
    }
}