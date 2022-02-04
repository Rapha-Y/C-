#ifndef _SYMTAB_H_
#define _SYMTAB_H_

/* Inserts line numbers and memory locations into the symbol table
 * loc = memory location is inserted only the first time, otherwise ignored */
void insertSymTab(int location, char *name, char *scope, char *typeData, int lineNum);

/* Returns the memory location of a variable */
int lookupSymTab(char *name, char *scope );

char* lookupTypeSymTab(char *name, char *scope);

/* Prints a formatted listing of the symbol table contents to the listing file*/
void printSymTab(FILE *listing);

#endif