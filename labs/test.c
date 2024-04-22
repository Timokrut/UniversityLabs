#include <stdio.h>

void print_array(char *arr) 
{
    for (int i = 0; i < 64; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

char count_weight(unsigned char number) 
{
    int counter = 0;
    while (number != 0) {
        if (number & 1)
            counter++;
        number >>= 1;
    }
    return counter;
}

char count_arr_weight(char* arr)
{
    char sum = 0;
    for (int i = 0; i < 64; i++)
    {
        if (arr[i] == 1)
        sum++;
    }
    return sum;
}

int main() {
    char x1 = 40;
    char arr[64] = {0};

    for (int i = 0; i < 64; ++i)
        arr[i] = count_weight(x1 ^ i) <= 3;

    print_array(arr);
    printf("%d\n", count_arr_weight(arr));
    return 0;
}
