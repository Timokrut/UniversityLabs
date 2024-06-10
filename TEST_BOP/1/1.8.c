// Напишите фрагмент программы из функции string.h, которая сравнивает на полное соответствие два массива A и B, состоящие из 83 элементов

#include <string.h>
#include <stdio.h>

int main()
{
    char A[84];
    char B[84];

    int cmp = strcmp(A, B);
    if (cmp == 0)
        printf("True");
    else
        printf("False");

    return 0;                
}
