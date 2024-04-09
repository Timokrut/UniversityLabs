#include <stdio.h>

int count_weight1(unsigned char* number)
{
    int i = 0; 
    int counter = 0;
    while (number[i] != '\0')
    {
        if (number[i] == '1')
            counter++;
        i++;    
    }

    return counter;
}


int count_weight2(unsigned char* number)
{
    int i = 0; 
    int counter = 0;
    while (number[i] != '\0')
    {
        counter += number[i] % 2;
        i++;    
    }

    return counter;
}


int main()
{
    unsigned char binary[9];
    scanf("%s", binary);
    printf("%d\n", count_weight1(binary));
    printf("%d\n", count_weight2(binary));
    return 0;
}