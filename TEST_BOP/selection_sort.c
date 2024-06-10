#include <stdio.h>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void selection_sort(int* arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;  
        }
        swap(&arr[min_idx], &arr[i]);
    }
}