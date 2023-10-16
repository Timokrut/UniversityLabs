#include "func.h"

int max_array(int arr[])
{
    int max_value = 0, length = arr[0];
    for (int i = 1; i <= length; i++)
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
    if (arr[0] == 0)
        printf("no numbers in array");
    else
        printf("max absolute number is %d", max_value);
    
    return 0;
}