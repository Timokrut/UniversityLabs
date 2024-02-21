#include "func.h"

// Ввести строку, вывести только слова, оканчивающиеся на согласную букву.

int main(){

    char data[100];
    printf("enter a string: ");

    int c;
    int index;
    while ((c = getchar()) != '\n' && index < 99)
    {
        data[index] = c;
        index ++;
    }
    data[index] = '\0';

    int word_start = 0;
    for (int i = 0; data[i] != '\0'; i++)
    {
        if (data[i] == ' ' || data[i + 1] == '\0')
        {
            //------------if (condition)->(i-1) else i
            int word_end = (data[i] == ' ' ? i - 1 : i);
            // int word_end;
            // if (data[i] == ' ')
            // word_end = i - 1;
            // else
            // word_end = i;

            if (isVowel(data[word_end]) == 0)
            {
                for (int j = word_start; j <= word_end; j++)
                {
                    putchar(data[j]);
                }
                putchar(' ');
            }

            word_start = i + 1;
        
        }
    }
    return 0;
}