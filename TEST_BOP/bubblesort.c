#include <stdio.h>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int bubble_sort(int* arr, int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1]) 
                swap(&arr[j], &arr[j + 1]);          
}

int main()
{
    int arr[] = {0, 5, 7, 8, 9, 2, 5, 7, 1, 4, 6, 3};
    int len = sizeof(arr) / sizeof(arr[0]);


    bubble_sort(arr, len);

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);    

    return 0;
}