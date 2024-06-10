// Напишите реализацию функции merge без дописывания “хвостов”
#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* aL = (int*)malloc(sizeof(int) * n1);
    int* aR = (int*)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++) aL = arr[left + i];    
    for (int i = 0; i < n2; i++) aR = arr[mid + i + 1]; 

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (aL[i] <= aR[j]) arr[k++] = aL[i++];
        else arr[k++] = aR[j++]; 
    }
}