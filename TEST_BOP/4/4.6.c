// Написать часть кода где выполняется универсальная сортировка пузырьком
#include <stdio.h>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int* arr, int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);            
}

int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, len);

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);    

    return 0;
}