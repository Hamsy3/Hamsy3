#include "vector.h"
#include "input.h"
int push (vector *vector, char elem) {
    if (vector->top == vector->size) {
        fprintf(stdout, "\nStack is full\n");
        return 1;
    } else {
        vector->top++;
        vector->data[vector->top] = elem;
    }
    return 0;
}
int pop(vector *vector) {
    if (vector->top == -1) {
        fprintf(stdout, "\nStack is empty\n");
        return 1;
    } else {
        vector->top--;
    }
    return 0;
}
void create_vector (vector *new, int size, int operand_size) {
    new->data = calloc(size + operand_size*2, sizeof(char));
    new->size = size + operand_size;
    new->top = -1;
}
void display (vector *vector) {
    for (int i = 0; i< vector->top; ++i) {
        fprintf (stdout, "%c", vector->data[i]);
    }
}
int postfix_to_infix (vector *vector, char* formula) {
    for (int i = 0; i < (int) strlen(formula); ++i) {
        if (if_operand(formula[i])) {
            if (push(vector, formula[i]) == 1) {
                return 1;
            }
            if (push(vector, ' ') == 1) {
                return 1;
            }
        } else {
            for (int j = vector->top-1; j > 0; --j) {
                if (vector->data[j] == ' ') {
                    vector->data[j] = formula[i];
                    break;
                }
            }
        }
    }
    return 0;
}
