#include "func.h"

// Ввести строку. Вывести строку так, чтобы за каждым словом следовало количество пробелов/точек, равное номеру слова в строке.

char fix_string(char* string)
{
    int multiplier = 0; // смотря как считать, 0 - если с индекса 0, 1 - если с индекса 1
    while (*string != '\0')
    {
        if (*string == ' ')
        {
            for (int i = 0; i < multiplier; i++)
            {
                printf(" ");
            }
            multiplier ++;
        }
        else
        {
            printf("%c", *string);
        }
        string++;
    }
    return *string;
}

int main()
{
    char string[] = "hello world i love u mom <3";
    fix_string(string);
    return 0;
}