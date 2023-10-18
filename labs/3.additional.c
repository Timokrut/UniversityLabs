#include <stdio.h>

double findMinFractionalPart(double arr[], int length) {
    if (length <= 0) {
        printf("Массив пуст\n");
        return 0.0;
    }

    int minIndex = 0;

    for (int i = 0; i < length; i++) {
        double fractional = arr[i] - (int)arr[i];
        if (fractional < (arr[minIndex] - (int)arr[minIndex])) {
            minIndex = i;
        }
    }

    return arr[minIndex];
}


int main() {
    int length;
    printf("Введите размер массива: ");
    scanf("%d", &length);

    if (length <= 0) {
        printf("Размер массива должен быть положительным числом.\n");
        return 1;
    }

    double arr[length];

    printf("Введите %d вещественных чисел:\n", length);
    for (int i = 0; i < length; i++) {
        scanf("%lf", &arr[i]);
    }

    double result = findMinFractionalPart(arr, length);

    printf("Число с наименьшей дробной частью: %lf\n", result);

    return 0;
}