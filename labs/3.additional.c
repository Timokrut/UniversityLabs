#include <stdio.h>

double minFractional(double arr[], int length) {
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
    printf("enter a length of array: ");
    scanf("%d", &length);

    double arr[length];

    for (int i = 0; i < length; i++) {
        printf("enter a number : ");
        scanf("%lf", &arr[i]);
    }

    double result = minFractional(arr, length);

    printf("number with min fractional part is %lf", result);

    return 0;
}