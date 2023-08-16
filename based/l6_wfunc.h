#include <stdio.h>

// void == returns nothing
void print_hello(){
    printf("Hello\n");
}


void sum(int a, int b){
    int res = a + b;
    printf("Sum of %d and %d equals %d\n", a, b, res);
    
}

void string(char arr[]){
    printf("%s\n", arr);
}


int mult(int a, int b){
    int res = a * b;
    return res;
}