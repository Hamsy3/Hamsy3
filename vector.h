#ifndef vector_h
#define vector_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct vector {
    char *data;
    int size;
    int top;
} vector;
int push (vector *vector, char elem);
int pop(vector *vector);
void create_vector (vector *new, int size, int operand_size);
void display (vector *vector);
int postfix_to_infix (vector *vector, char* formula);
#endif
