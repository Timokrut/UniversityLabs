// Написать программу с работой над массивом на n элементов со сложностью c*(n/2)

#include <stdio.h>

void print_half_array(int* array, int length)
{
    for (int i = 0; i < length / 2; i++)
        printf("%d ", array[i]);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr)/sizeof(arr[0]);

    print_half_array(arr, length);

    return 0;    
}