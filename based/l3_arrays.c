#include <stdio.h>

int main(){
    //array[number of elements] = {numbers initialization} (if init u dont need to write number of elements -> array[])
    int arr[] = {1, 2, 3, 4, 5};
    // new value
    arr[0] = 123;
    printf("first element of array - %d\n", arr[0]);

    float numbers[3];
    numbers[0] = 5.123f;
    numbers[1] = 4.13f;
    numbers[2] = 6.334f;


    // both are equal
    char word[] = {'M', 'a', 'm', 'u', 't'};
    char words[] = "Raxal <3";
    printf("%c\n", word[0]);
    printf("%s\n", words);


    // 2d array 
    // array[number on lines][amount of numbers on one line]
    int array[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    array[1][1] = 100;

    printf("%d", array[1][1]);


    return 0;
} 