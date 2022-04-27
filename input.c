#include "input.h"

void input_formula (char **formula) {
    *formula[0] = '\0';
    char c = '\0';
    int counter = 1;
    (c = getchar());
    while ((c !='\n')) {
        if (counter > 1) {
            c = getchar();
        }
            *formula = (char*) realloc (*formula, counter+1);
            strncat (*formula, &c, 1);
            counter++;
    }
}
