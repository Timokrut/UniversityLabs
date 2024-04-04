#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "header.h"

void print_test()
{
system("clear");        
printf("  _______________________\n");
printf(" /_  __/ ____/ ___/_  __/\n");
printf("  / / / __/  |__ | / /   \n");
printf(" / / / /___ ___/ // /    \n");
printf("/_/ /_____//____//_/     \n");
}


void* bin(int number, int result[], int* length)
{
    int i = 0;
    int len = 0;

    if (number == 0) {
        len = 1;
        *length = len;

        return result;
    }

    for (i = 0; number > 0; i++) {
        result[i] = number % 2;
        number /= 2;
        len++;
    }

    *length = len;
    return result;
}

void print_binary(int number[], int* length)
{
    for (int i = *length - 1; i >= 0; i--)
        printf("%d", number[i]);    

    printf("\n");
}


int max(size_t num1, size_t num2)
{
    return (num1 < num2) ? num2 : num1;
}


int count_zeroes(int digits[], int* length)
{
    if (*length == 1)
        return digits[0] == 0 ? 1 : 0;
    else {
    int maxlen = 0;
    int curlen = 0;

    for (int i = 0; i < *length; i++)
    {
        if (digits[i] == 0) {
            curlen++;
            maxlen = max(curlen, maxlen);
        }
        else 
            curlen = 0;
    }

    return maxlen;
    }
}


int count_ones(int digits[], int* length)
{
    if (*length == 1)
        return digits[0] == 1 ? 1 : 0;
    else {
    int maxlen = 0;
    int curlen = 0;

    for (int i = 0; i < *length; i++)
    {
        if (digits[i] == 1) {
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



void generate_binary(int num_zeros, int num_ones) 
{
    int total_digits = num_zeros + num_ones;
    int i, j;
    char **result = NULL;
    int count = 0;

    result = (char**)malloc(sizeof(char*) * (1 << total_digits));

    for (i = 0; i < (1 << total_digits); i++) {
        char *binary = (char *)malloc(sizeof(char) * (total_digits + 1));

        int num = i;
        for (j = total_digits - 1; j >= 0; j--) {
            binary[j] = (num % 2) + '0';
            num /= 2;
        }
        binary[total_digits] = '\0';

        int zero_count = 0, one_count = 0;
        for (j = 0; j < total_digits; j++) {
            if (binary[j] == '0') {
                zero_count++;
            } else {
                one_count++;
            }
        }
        if (zero_count == num_zeros && one_count == num_ones) {
            result[count++] = binary;
        } else {
            free(binary);
        }
    }

    printf("Generated binary numbers with %d zeros and %d ones:\n", num_zeros, num_ones);
    for (i = 0; i < count; i++) {
        int sum = 0;
        printf("Binary - %s, Decimal - ", result[i]);
        for (j = 0; j < total_digits; j++)
            sum += (1 << (total_digits - j - 1)) * (result[i][j] - '0');
        
        printf("%d\n", sum);                    
        free(result[i]);
    }

    free(result);
}


void tests()
{
    int result[256] = {0};
    int length = 0;

    // Number = 0
    int number1 = 0;
    bin(number1, result, &length);
    assert(length == 1);
    assert(result[0] == 0);

    // Number = 1
    int number2 = 1;
    bin(number2, result, &length);
    assert(length == 1);
    assert(result[0] == 1);

    // Number = 1101
    int number3 = 1101;
    bin(number3, result, &length);
    assert(length == 11);
    assert(result[0] == 1 && result[1] == 0 && result[2] == 1 && result[3] == 1 && result[4] == 0 && result[5] == 0 && result[6] == 1 && result[7] == 0 && result[8] == 0 && result[9] == 0 && result[10] == 1 );

    printf("bin() tests passed successfully\n");
    int result1[256] = {0};
    // Number = 0
    assert(count_zeroes(bin(0, result1, &length), &length) == 1);
    // Number = 1
    assert(count_zeroes(bin(1, result1, &length), &length) == 0);
    // Number = 1101
    assert(count_zeroes(bin(1101, result1, &length), &length) == 3);

    printf("count_zeroes() tests passed successfully\n");

    int result2[256] = {0};
    // Number = 0
    assert(count_ones(bin(0, result2, &length), &length) == 0);
    // Number = 1
    assert(count_ones(bin(1, result2, &length), &length) == 1);
    // Number = 1101
    assert(count_ones(bin(1101, result2, &length), &length) == 2);

    printf("count_ones() tests passed successfully\n\n");
    printf("All tests passed successfully!\n\n");


    printf("Press Any Key to Continue\n");  
    getchar();    
    system("clear");
}