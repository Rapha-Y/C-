#include "semantics.h"

#define SIZE 256
#define MAXTOKENLEN 64

typedef struct Param {
    int type;
    char name[MAXTOKENLEN];
    int i_val;
    int *arr_vals;
    int arr_size;
} Param;

typedef struct Occur {
    int line;
    struct Occur *next;
} Occur;

typedef struct Token {
    int type;
    char name[MAXTOKENLEN];
    int i_val;
    int *arr_vals;
    int arr_size;
    int ret_type;
    Param *params;
    int par_num;
    Occur *first;
    struct Token *next;
} Token;

static Token **h_table;

void init_table();
unsigned int hash(char *key);
void insert_token(char *name, int len, int type, int line);
Token *search_token(char *name);
void symtab_dump(FILE *of); 