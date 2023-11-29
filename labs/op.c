#include <stdio.h>

int main(){

    char data[101];
    data[0] = '!';
    printf("enter a string: ");

    int c;
    int index = 1;
    while ((c = getchar()) != '\n' && index < 99)
    {
        data[index] = c;
        index ++;
    }
    data[index] = '\0';

    int word_end = index;

    for (int i = word_end; data[i] != '!'; i--)
    {
        if (data[i] == ' ' || data[i - 1] == '!')
        {
            int word_start = i;
            if (data[i] == ' ')
            word_start = i + 1;
            else
            word_start = i;

            for (int j = word_start; j <= word_end; j++)
                putchar(data[j]);
            
            putchar(' ');

            word_end = i - 1;
        }
    }
    return 0;
}