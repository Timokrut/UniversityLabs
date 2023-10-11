#include "func.h"

int max_array(int arr[])
{
    int max_value = 0;
    int length = arr[0];

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
    scanf("%d", &length);

    int arr[length + 1];
    arr[0] = length;

    for (int i = 1; i <= length; i++)
    {
        printf("enter a number: ");
        scanf("%d", &number);
        arr[i] = number;
    }    

    int max_value = max_array(arr); 
    printf("%d", max_value);

    return 0;
}