#define SIZE 256
#define MAXTOKENLEN 64

#define UNDEF 0
#define INT_TYPE 1
#define ARRAY_TYPE 2
#define FUNCTION_TYPE 3

typedef struct Param {
    int par_type;
    char param_name[MAXTOKENLEN];
    int ival; double fval; char *st_sval;
} Param;

typedef struct RefList {
    int lineno;
    struct RefList *next;
    int type;
} RefList;

//list node
typedef struct list_t {
    char st_name[MAXTOKENLEN];
    int st_size;
    int scope;
    RefList *lines;
    int st_ival; double st_fval; char *st_sval;
    int st_type;
    int inf_type;
    int *i_vals; double *f_vals; char **s_vals;
    int array_size;
    Param *parameters;
    int num_of_pars;
    struct list_t *next;
} list_t;

static list_t **hash_table;

void init_hash_table(); // initialize hash table
unsigned int hash(char *key); // has function
void insert(char *name, int len, int type, int lineno); // insert entry
list_t *lookup(char *name); // search for entry
list_t *lookup_scope(char *name); // search for entry in scope
void hide(); // hide the current scope
void hide_scope(int scope); // hide a specific scope
void symtab_dump(FILE *of); //dump file 