#include <stdio.h>
#include "header.h"

int main()
{
    long number;
    char result[120];

    scanf("%ld", &number);
    
    decTo11th(number, result);
    printf("%s\n", result);
    
    // test_decTo11th();
    return 0;
}