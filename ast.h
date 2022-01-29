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
AST_node *new_AST_decl_node(int data_type, Token **names);
AST_node *new_AST_const_node(int const_type, Value val);