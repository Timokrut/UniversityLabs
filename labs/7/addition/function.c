#include <stdio.h>

void decimalToBase11(int decimal, int base11[]) {
    int i = 0;
    
    if (decimal == 0) 
        base11[0] = 0;

    while (decimal > 0) {
        base11[i] = decimal % 11;
        decimal /= 11;
        i++;
    }
}

void printBase11(int base11[]) {
    int i;
    for (i = 10; i >= 0; i--) {
        if (base11[i] != 0)
            break;
    }
    for (i; i >= 0; i--)
        printf("%d", base11[i]);
}

void base11Addition(int num1[], int num2[], int result[]) {
    int remainder = 0;
    for (int i = 0; i < 11; i++) {
        result[i] = (num1[i] + num2[i] + remainder) % 11;
        remainder = (num1[i] + num2[i] + remainder) / 11;
    }
}

void base11Subtraction(int num1[], int num2[], int result[]) {
    int borrow = 0;
    for (int i = 0; i < 11; i++) {
        int diff = num1[i] - num2[i] - borrow;
        if (diff < 0) {
            diff += 11;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = diff;
    }
}

void base11Division(int dividend, int divisor, int result[]) {
    int number = dividend / divisor;
    decimalToBase11(number, result);
}


void base11Multiplication(int num1[], int num2[], int result[]) {
    int temp[22] = {0};
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            temp[i + j] += num1[i] * num2[j];
        }
    }
    int remainder = 0;
    for (int i = 0; i < 22; i++) {
        result[i] = (temp[i] + remainder) % 11;
        remainder = (temp[i] + remainder) / 11;
    }
}

