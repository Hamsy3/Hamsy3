#ifndef input_h
#define input_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int if_operand (char elem);
int if_operator (char elem);
int input_formula (char **formula, int *operand_counter, int *operator_counter);
#endif
