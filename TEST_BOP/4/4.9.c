//Написать рекурсию для поиска максимального элемента
#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int find_max(int* arr, int len)
{
    if (len == 1)
        return arr[0];
    else
        return max(arr[len-1], find_max(arr, len - 1));        
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int max_number = find_max(arr, sizeof(arr)/sizeof(arr[0]));
    
    printf("%d", max_number);

    return 0;
}