#include <stdio.h>
#include "func.h"

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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 10, 2, -100};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("%d", max_array(arr, len));

    return 0;
}
