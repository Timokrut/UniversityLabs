#include <stdio.h>
#include <stdlib.h>

void mergeArrays(int* arr1, int* arr2, int len1, int len2, int* mergedArray) {
    int i = 0, j = 0, k = 0;

    while (i < len1 && j < len2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray[k++] = arr1[i++];
        }
        else {
            mergedArray[k++] = arr2[j++];
        }
    }

    while (i < len1) {
        mergedArray[k++] = arr1[i++];
    }

    while (j < len2) {
        mergedArray[k++] = arr2[j++];
    }
}

int main() {
    int capacity1 = 10; // Initial capacity for arr1
    int capacity2 = 10; // Initial capacity for arr2
    int size1 = 0;      // Number of elements in arr1
    int size2 = 0;      // Number of elements in arr2
    int *arr1 = malloc(capacity1 * sizeof(int));
    int *arr2 = malloc(capacity2 * sizeof(int));
    int *mergedArray;
    int num;

    printf("Введите числа первого массива (для завершения ввода нажмите Enter):\n");
    while (1) {
        int c = getchar();
        if (c == '\n')
            break;
        ungetc(c, stdin);
        if (scanf("%d", &num) != 1)
            break;
        arr1[size1++] = num;
        if (size1 >= capacity1) {
            capacity1 *= 2;
            arr1 = realloc(arr1, capacity1 * sizeof(int));
        }
    }

    printf("Введите числа второго массива (для завершения ввода нажмите Enter):\n");
    while (1) {
        int c = getchar();
        if (c == '\n')
            break;
        ungetc(c, stdin);
        if (scanf("%d", &num) != 1)
            break;
        arr2[size2++] = num;
        if (size2 >= capacity2) {
            capacity2 *= 2;
            arr2 = realloc(arr2, capacity2 * sizeof(int));
        }
    }

    mergedArray = malloc((size1 + size2) * sizeof(int));
    mergeArrays(arr1, arr2, size1, size2, mergedArray);

    printf("Результат объединения двух массивов: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedArray[i]);
    }

    free(arr1);
    free(arr2);
    free(mergedArray);

    return 0;
}
