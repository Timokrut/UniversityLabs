#include <stdio.h>

void decTo11th(int number)
{
    int result[1024], i = 0;


    for (i = 0; number > 0; i++)
    {
        result[i] = number % 11;
        number /= 11;
    }

    for (i = i - 1; i >= 0; i--)
    if (result[i] == 10) printf("A");
    else printf("%d", result[i]);
}

int main()
{
    long number = 10;
    decTo11th(number);
    return 0;
}