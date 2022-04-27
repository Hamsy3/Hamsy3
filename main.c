#include "input.h"
#include "vector.h"
int main() {
    char *formula = calloc (1, sizeof(char));
    int operand_counter = 0;
    int operator_counter = 0;
    while ((formula[0] == '\0') || (strlen(formula)<3) || (formula[0] < 'A') || ((formula[0] > 'Z') && (formula[0] < 'a')) || (formula[0] > 'z') || (formula[1] < 'A') || ((formula[1] > 'Z') && (formula[1] < 'a')) || (formula[1] > 'z') || (operator_counter != (operand_counter-1))) {
            if (input_formula(&formula, &operand_counter, &operator_counter) == 1) {
                printf ("\nEOF\n");
                free (formula);
                return 1;
            }
            if ((formula[0] == '\0') || (strlen(formula)<3) || (formula[0] < 'A') || ((formula[0] > 'Z') && (formula[0] < 'a')) || (formula[0] > 'z') || (formula[1] < 'A') || ((formula[1] > 'Z') && (formula[1] < 'a')) || (formula[1] > 'z') || (operator_counter != (operand_counter-1))) {
                printf("Please, correct input\n");
                operand_counter = 0;
                operator_counter = 0;
            }
    }
    vector new;
    create_vector(&new, (int)strlen(formula), operand_counter);
    if (postfix_to_infix(&new, formula) == 1) {
        return 1;
    }
    display(&new);
    printf("\n");
    free (formula);
    free (new.data);
    return 0;
}
