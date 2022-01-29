typedef enum Node_type {
    BASIC_NODE,
    DECL_NODE,
    CONST_NODE,
    IF_NODE,
    ELIF_NODE,
    WHILE_NODE,
    ASSIGN_NODE,
    MAIN_NODE,
    FUN_CALL,
    MATH_NODE,
    COMP_NODE,
    FUN_DECL,
    RET_NODE,
} Node_type;

typedef enum Math_op {
    ADD,
    SUB,
    MULT,
    DIV,
} Math_op;

typedef enum Comp_op {
    LT,
    LTE,
    GTE,
    GT,
    EQ,
    DIFF,
} Comp_op;

typedef union Value {
    int i_val;
} Value;

typedef struct AST_node {
    enum Node_type type;
    struct AST_node *left;
    struct AST_node *right;
} AST_node;

typedef struct AST_node_decl {
    enum Node_type type;
    int data_type;
    Token** names;
    int names_count;
} AST_node_decl;

typedef struct AST_node_const {
    enum Node_type type;
    int const_type;
    Value val;
} AST_node_const;

typedef struct AST_node_if {
    enum Node_type type;
    struct AST_node *condition;
    struct AST_node *if_branch;
    struct AST_node **elif_branches;
    int elif_count;
    struct AST_node *else_branch;
} AST_node_if;

typedef struct AST_node_elif {
    enum Node_type type;
    struct AST_node *condition;
    struct AST_node *elif_branch;
} AST_node_elif;

typedef struct AST_node_while {
    enum Node_type type;
    struct AST_node *condition;
    struct AST_node *while_branch;
} AST_node_while;

typedef struct AST_node_assign {
    enum Node_type type;
    Token *entry;
    struct AST_node *assign_val;
} AST_node_assign;

typedef struct AST_node_main {
    enum Node_type type;
    int statement_type;
} AST_node_main;

typedef struct AST_node_func_call {
    enum Node_type type;
    Token *entry;
    AST_node **params;
    int param_num;
} AST_node_func_call;

typedef struct AST_node_math {
    enum Node_type type;
    enum Math_op op;
    struct AST_node *left;
    struct AST_node *right;
} AST_node_math;

typedef struct AST_node_comp {
    enum Node_type type;
    enum Comp_op op;
    struct AST_node *left;
    struct AST_node *right;
} AST_node_comp;

typedef struct AST_node_fun_decl {
    enum Node_type type;
    int ret_type;
    Token *entry;
} AST_node_fun_decl;

typedef struct AST_node_ret {
    enum Node_type type;
    int ret_type;
    struct AST_node *ret_val;
} AST_node_ret;

AST_node *new_AST_node(Node_type type, AST_node *left, AST_node *right);
AST_node *new_AST_decl_node(int data_type, Token **names, int names_count);
AST_node *new_AST_const_node(int const_type, Value val);
AST_node *new_AST_if_node(AST_node *condition, AST_node *if_branch, AST_node **elif_branches, int elif_count, AST_node *else_branch);
AST_node *new_AST_elif_node(AST_node *condition, AST_node *elif_branch);
AST_node *new_AST_while_node(AST_node, *condition, AST_node *while_branch);
AST_node *new_AST_assign_node(Token *entry, AST_node *assign_val);
AST_node *new_AST_main_node(int statement_type);
AST_node *new_AST_fun_call_node(Token *entry, AST_node **params, int param_num);
AST_node *new_AST_math_node(enum Math_op op, AST_node *left, AST_node *right);
AST_node *new_AST_comp_node(enum Comp_op op, AST_node *left, AST_node *right);
AST_node *new_AST_fun_decl_node(int ret_type, Token *entry);
AST_node *new_AST_ret_node(int ret_type, AST_node *ret_val);
void AST_print_node(AST_node *node);
void AST_traversal(AST_node *node);