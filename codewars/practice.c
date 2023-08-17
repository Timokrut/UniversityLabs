// Напишите программу на C, которая принимает два целых числа, и проверьте, равны они или нет.

#include <stdio.h>
#include <locale.h>

int main()
{
    int x, y;

    printf("введите первое число:");
    scanf("%d", &x);

    printf("введите второе число:");
    scanf("%d", &y);

    if (x == y)
    {
        printf("%d и %d равны\n", x, y);
    }
    else
    {
        printf("%d не %d равны\n", x, y);
    }

    return 0;
}