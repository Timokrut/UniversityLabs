// Дан массив а, скопировать символы с 65 по 85 в начало массива в

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[100];

    for (int i = 0; i < 100; i++)
        arr[i] = i;


    int idx1 = 65;
    int idx2 = 85 + 1;   
    int length = idx2 - idx1;

    int result[sizeof(arr) / sizeof(arr[0]) + length];

    
    memcpy(result, arr + idx1, length * sizeof(int));
    
    memcpy(result + length, arr, sizeof(int) * (sizeof(arr) / sizeof(arr[0])));

    for (int i = 0; i < 100; i++)
        printf("%d ", result[i]);

    return 0;            
}