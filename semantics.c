#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantics.h"

int get_ret_type(int type_a, int type_b, int op_type) {
    switch(op_type) {
        case NONE:
            if((type_a == INT_TYPE) && (type_b == INT_TYPE)) return 1;
            else type_error(type_a, type_b, op_type);
        case MATH_OP:
            if((type_a == INT_TYPE) && (type_b == INT_TYPE)) return INT_TYPE;
            else type_error(type_a, type_b, op_type);
        case COMP_OP:
            if((type_a == INT_TYPE) && (type_b == INT_TYPE)) return INT_TYPE;
            else type_error(type_a, type_b, op_type);
        default:
            fprintf(stderr, "Error in operator selection!\n");
			exit(1);
    }
}

void type_error(int type_a, int type_b, int op_type) {
    fprintf(stderr, "Type conflict between %d and %d using op type %d\n", type_a, type_b, op_type);
	exit(1);
}
