#include <stdio.h>
#include <assert.h>

#include "header.h"

void* bin(int number, int result[], int* length)
{
    int i = 0;
    int len = 0;

    if (number == 0) {
        result[0] = 0;
        len = 1;
        printf("0\n");

        *length = len;
        return result;
    }

    for (i = 0; number > 0; i++) {
        result[i] = number % 2;
        number /= 2;
        len++;
    }

    for (int i = len - 1; i >= 0; i--)
        printf("%d", result[i]);    

    printf("\n");

    *length = len;
    return result;
}

int max(size_t num1, size_t num2)
{
    return (num1 < num2) ? num2 : num1;
}

int count_zeroes(int digits[], int* length)
{
    if (*length == 1)
        return *length - digits[0];
    else {
    int maxlen = 0;
    int curlen = 0;

    for (int i = 0; i < *length; i++)
    {
        if (digits[i] == 0) {
            curlen++;
            maxlen = max(curlen, maxlen);
        }
        else {
            curlen = 0;
        }
    }

    return maxlen;
    }
}

void test_countzeroes()
{
    int result[256];
    int length = 0;

    // Number = 0
    assert(count_zeroes(bin(0, result, &length), &length) == 1);
    printf("Test 1 passed\n");

    // Number = 1
    assert(count_zeroes(bin(1, result, &length), &length) == 0);
    printf("Test 2 passed\n");

    // Number = 1101
    assert(count_zeroes(bin(1101, result, &length), &length) == 3);
    printf("Test 3 passed\n");

    printf("All tests passed successfully!\n");

}