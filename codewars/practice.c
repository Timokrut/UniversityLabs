// Напишите программу на C, которая принимает два целых числа, и проверьте, равны они или нет.

#include <stdio.h>

int main()
{
    int x,y;
    ptintf("введите первое число:");
    scanf("%d", &x);
    ptintf("введите второе число:");
    scanf("%d",&y);

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