#include <stdio.h>
#include "header.h"


int main()
{
    int number = 0;
    int result[256] = {0};
    int length = 0;

    print_test();
    tests();


    printf("Enter decimal number: ");
    scanf("%d", &number);

    printf("Your number in binary - ");
    print_binary(bin(number, result, &length), &length);

    int zeroes = count_zeroes(bin(number, result, &length), &length);
    int ones = count_ones(bin(number, result, &length), &length);

    generate_binary(zeroes, ones);


    return 0;
}
