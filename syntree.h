typedef struct Syn_tree_node {
    char *value;
    struct Syn_tree_node *next_sibling;
    struct Syn_tree_node *first_child;
} Syn_tree_node;

typedef struct Syn_tree {
    Syn_tree_node *root;
    int root_sibling_total;
} Syn_tree;

void init_syn_tree();
void insert_syn_tree(char *value, int child_num);
void print_tree();