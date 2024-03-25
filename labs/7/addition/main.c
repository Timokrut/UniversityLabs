#include <stdio.h>
#include "header.h"

int main() {
    int decimal1, decimal2;
    printf("Enter the first decimal number: ");
    scanf("%d", &decimal1);
    printf("Enter the second decimal number: ");
    scanf("%d", &decimal2);

    int base11_1[11] = {0};
    int base11_2[11] = {0};

    int addition[22] = {0};
    int difference[22] = {0};
    int multiplication[22] = {0};
    int division[22] = {0};

    decimalToBase11(decimal1, base11_1);
    decimalToBase11(decimal2, base11_2);

    printf("First number in base 11:  ");
    printBase11(base11_1);
    printf("\nSecond number in base 11: ");
    printBase11(base11_2);
    printf("\n");

    base11Addition(base11_1, base11_2, addition);
    printf("Sum in base 11: ");
    printBase11(addition);
    printf("\n");

    base11Subtraction(base11_1, base11_2, difference);
    printf("Difference in base 11: ");
    printBase11(difference);
    printf("\n");

    base11Multiplication(base11_1, base11_2, multiplication);
    printf("Multiplication in base 11: ");
    printBase11(multiplication);
    printf("\n");

    base11Division(decimal1, decimal2, division);
    printf("Divison in base 11: ");
    printBase11(division);
    printf("\n");

    return 0;
}
