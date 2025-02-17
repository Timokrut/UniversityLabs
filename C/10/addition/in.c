#include "output_file.h"

int main() {
    int num1, num2, sum;

    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);
    sum = num1 + num2;

    printf("Sum: %d\n", sum);
    return 0;
}