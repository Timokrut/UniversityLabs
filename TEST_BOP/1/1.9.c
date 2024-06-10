// Написать генератор случайных чисел от 10 до 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a;
    srand(time(NULL));
    a = rand() % 91 + 10;
    printf("%d", a);
}

