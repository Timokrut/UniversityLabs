#include "stdio.h"

// Ввести строку. Вывести строку так, чтобы за каждым словом следовало количество пробелов/точек, равное длине строки.

void swap_spaces(char* str)
{
    int i = 0, j = 0;
    int foundSpace = 0;

    while (str[i] != '\0') 
    {
        if (str[i] == ' ') 
        {
            if (foundSpace == 0) 
            {
                str[j] = str[i];
                j++;
                foundSpace = 1;
            }
        } 
        else 
        {
            str[j] = str[i];
            j++;
            foundSpace = 0;
        }
        i++;
    }
    str[j] = '\0';
}

char fix_string(char* string)
{
    int multiplier = 0;
    while (*string != '\0')
    {
        if (*string == ' ')
        {
            for (int i = 0; i < multiplier; i++)
            {
                printf(".");
            }
            multiplier = 0;
        }
        else
        {
            printf("%c", *string);
            multiplier ++;
        }
        string++;
    }
    return *string;
}

int main()
{
    char string[100];
    printf("enter a string: ");

    int c;
    int index;
    while ((c = getchar()) != '\n' && index < 99)
    {
        string[index] = c;
        index ++;
    }
    string[index] = '\0';
    swap_spaces(string);
    fix_string(string);
    return 0;
}