// Напишите фрагмент программы, которая сравнивает min и текущий элемент для универсальной сортировки на основе сортировки выбором

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
        swap(&arr[i], &arr[min_idx]);
    }
    
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 0};
    int len = sizeof(arr) / sizeof(arr[0]);

    int a = 3;
    int b = 2;

    selection_sort(arr, len);

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);    

    return 0;
}
