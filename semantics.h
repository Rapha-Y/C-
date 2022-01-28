#define UNDEF 0
#define VOID_TYPE 1
#define INT_TYPE 2
#define ARRAY_TYPE 3
#define FUNCTION_TYPE 4

#define NONE 0
#define MATH_OP 1
#define COMP_OP 2

int get_ret_type(int type_a, int type_b, int op_type);
void type_error(int type_a, int type_b, int op_type);