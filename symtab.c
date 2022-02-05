#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "symtab.h"
#define FILESIZE 216
#define SHIFT 4

typedef struct Line { 
    int lineNum;
    struct Line *next;
} *Line;

typedef struct SymItem { 
    Line lines;
    int memloc ; 
	char *name;
    char *scope;
	char *typeData; 
    struct SymItem *next;
} *SymItem;

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

void insertSymTab(int location, char *name, char *scope, char *typeData, int lineNum) {
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
        newItem->memloc = location;
        newItem->scope = scope;
        newItem->typeData = typeData;
        newItem->next = hashTable[hashCode];
        hashTable[hashCode] = newItem; 
    } else {
        Line line = item->lines;
        while (line->next != NULL) {
            line = line->next;
        }
        line->next = (Line) malloc(sizeof(struct Line));
        line->next->lineNum = lineNum;
        line->next->next = NULL;  
    }
}

void printSymTab(FILE *listing) {
    int i;
    
    fprintf(listing,"Localizacao        Nome          Escopo           Tipo         Linha    \n");
    fprintf(listing,"----------------------------------------------------------------------------\n");
    for (i=0; i<FILESIZE; i++) {
        if (hashTable[i] != NULL) {
            SymItem item = hashTable[i];
            while (item != NULL) {
                fprintf(listing, "%-15d ", item->memloc);
                fprintf(listing, "%-15s  ", item->name);
		        fprintf(listing, "%-15s  ", item->scope);
		        fprintf(listing, "%-10s  ", item->typeData);	
                
                Line line = item->lines;
                while (line != NULL) { 
                    fprintf(listing, "%4d ", line->lineNum);
                    line = line->next;
                }
                fprintf(listing, "\n");
                item = item->next;
            }
        }
    }
}

// int main(int argc, char *argv[]) {
//     FILE *teste;
//     teste  = fopen ("teste.txt", "w");

//     insertSymTab(317, "testSymbol", "local", "int", 54);
//     insertSymTab(218, "testSymbol", "global", "int", 31);
//     insertSymTab(638, "outro", "global", "char", 11);
//     insertSymTab(317, "testSymbol", "local", "int", 60);

//     printSymTab(teste);
// }