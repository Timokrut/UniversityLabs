// Создайте и удалите массив на куче из 10 дробных

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr;
    arr = (int*)malloc(sizeof(int) * 10);

    free(arr);
    return 0;
}