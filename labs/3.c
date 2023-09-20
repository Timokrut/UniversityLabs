#include <stdio.h>

int max_array(int arr[], int len)
{
    int max_value = 0;

    for (int i = 0; i < len; i++)
    {
        if (max_value < arr[i])
            max_value = arr[i];
    }
    
    return max_value;       
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 10, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    printf("%d", max_array(arr, len));
    
    return 0;
}
