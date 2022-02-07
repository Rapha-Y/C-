typedef struct Line { 
    int lineNum;
    struct Line *next;
} *Line;

typedef struct SymItem { 
    Line lines;
	char *name;
    char *scope;
    char *declarationType;
	char *type; 
    struct SymItem *next;
} *SymItem;

void buildSymTab(Syn_tree *tree);
void printSymTab(FILE *listing);