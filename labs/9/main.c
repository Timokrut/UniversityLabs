#include <stdio.h>
#include "header.h"


int main()
{
    int number = 0;
    int result[256];
    int length = 0;

    scanf("%d", &number);
    printf("%d\n", count_zeroes(bin(number, result, &length), &length));

    // test_countzeroes();

    return 0;
}
