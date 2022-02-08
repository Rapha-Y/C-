void semantic_check(Syn_tree *tree);
int decl_before_use(Syn_tree *node); //difficult - vars/funs must be declared first
int last_decl_main(Syn_tree *node); //done - last decl is void main
int void_for_fun(Syn_tree *node); //doable - void is a type exclusive to functions
int if_int_cond(Syn_tree *node); //difficult - if condition has to end in an int
int while_int_cond(Syn_tree *node); //difficult - same as above
int fun_ret_val(Syn_tree *node); //difficult - int functions must return int, void mustn't return anything
int arr_int_brack(Syn_tree *node); //difficult - expressions inside brackets must end in int
int simp_exp_val(Syn_tree *node); //difficult - this one is hard to explain, go read the doc
int param_match(Syn_tree *node); //difficult - match parameter types for call
int global_fun(Syn_tree *node); //not sure - input and output are available without initialization