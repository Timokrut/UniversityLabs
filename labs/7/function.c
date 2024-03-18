#include <stdio.h>
#include <assert.h>
#include <string.h> 

#include "header.h"

char* decTo11th(long number, char result[])
{
    int i = 0;
    char current;

    if (number == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    for (i = 0; number > 0; i++) {

        current = number % 11;

        if (current == 10)
            result[i] = 'A';
        else
            result[i] = current + 48;
        number /= 11;
    }

    result[i] = '\0';
    int j;
    for (j = 0; j < i / 2; j++) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    return result;
}

// TEST's 

void test_decTo11th()
{
    char result[120];

    // Test case 1: 
    decTo11th(120, result);
    assert(strcmp(result, "AA") == 0);
    printf("Test 1 passed\n");

    // Test case 2: 
    decTo11th(11, result);
    assert(strcmp(result, "10") == 0);
    printf("Test 2 passed\n");

    // Test case 3: 
    decTo11th(0, result);
    assert(strcmp(result, "0") == 0);
    printf("Test 3 passed\n");


    printf("All tests passed successfully!\n");

}