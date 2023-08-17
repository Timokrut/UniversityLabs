// Напишите программу на C, которая принимает два целых числа, и проверьте, равны они или нет.

#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int x , y;
    printf("введите первое число:\n");
    scanf("%d", &x);
    printf("введите второе число:\n");
    scanf("%d", &y);

    if (x==y)
    {
        printf("%d и %d равны", x , y);
    }
    else
    {
        printf("%d не %d равны", x , y);
    }

    return 0;
}