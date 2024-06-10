#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; 
    int n2 = right - mid;

    int* aL = (int*)malloc(sizeof(int) * n1);
    int* aR = (int*)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++)
        aL[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        aR[i] = arr[mid + i + 1];

    int i = 0;                
    int j = 0;  

    int k = left;                

    while (i < n1 && j < n2)
    {
        if (aL[i] < aR[j]) arr[k] = aL[i++];
        else arr[k] = aR[j++];
        k++;
    }

    while (i < n1)
    {
        arr[k] = aL[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = aR[j];
        j++;
        k++;
    }
    free(aL);
    free(aR);
}

void mergesort(int* arr, int left, int right)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main()
{
    int arr[] = {5, 3, 7, 8, 1, 6, 9, 10, 4, 2};

    mergesort(arr, 0, 9);

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);    

    return 0;
}