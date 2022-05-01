#include "input.h"
int if_operand (char elem) {
    if ((elem >= 'a' && elem <= 'z') || (elem >= 'A' && elem <= 'Z')) {
        return 1;
    }
    return 0;
}
int if_operator (char elem) {
    if ((elem == '+') || (elem == '*') || (elem == '-') || (elem == '/')) {
        return 1;
    }
    return 0;
}
int input_formula (char **formula, int *operand_counter, int *operator_counter) {
    *formula[0] = '\0';
    char c = '\0';
    int counter = 1;
    while ((c = getchar()) && (c !='\n')) {
            if (c == EOF) {
            return 1;
            }
            *formula = (char*) realloc (*formula, counter+1);
            if ((if_operand(c)) || (if_operator(c))) {
                    strncat (*formula, &c, 1);
            }
        if (if_operand(c)) {
            (*operand_counter)++;
        }
        if (if_operator(c)) {
            (*operator_counter)++;
        }
            counter++;
    }
    return 0;
}
