// Напишите фрагмент программы в котором вычисляются с помощью цикла n=2^13 
// а затем выделяется массив дробных чисел такого же размера с помощью malloc

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base = 1;
    int pow = 13;
    for (int i = 0; i < pow; i++)
    {
        base *= 2;
    }
    
    float* arr = (float*)malloc(sizeof(float) * base);
    free(arr); 

    return 0;
}