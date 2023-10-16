#include "func.h"
// Написать функцию нахождения в массиве целых чисел наибольшего по абсолютной величине числа.

int max_array(int arr[], int length)
{
    int max_value = 0;
    for (int i = 0; i < length; i++)
    {
        if (abs(max_value) < abs(arr[i]))
            max_value = abs(arr[i]);
    }
    return max_value;
}


int main()
{
    int length, number;
    printf("how much numbers will be in array: ");
    scanf("%d\n", &length);
    int arr[length];
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &number);
        arr[i] = number;
    }
    
    printf("max absolute number is %d", max_array(arr, length));
    return 0;
}
