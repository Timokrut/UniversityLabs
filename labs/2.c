#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Ввести строку, вывести только слова, оканчивающиеся на согласную букву.

int main(){

    char string[100];
    char vowels[] = "aeiou";
    bool flag = true;

    while (true)
    {
        printf("enter '!' to end program\n");

        // enter a string
        scanf("%s", string);

        // requirement to end program
        if (strcmp(string, "!") == 0)
        break;

        // index of last element
        int l_idx = strlen(string) - 1; 

        // checking if last symbol is vowel or consonant
        for (int i = 0; i <= 4; i++)
        {
            if (vowels[i] == tolower(string[l_idx]))
            {
                flag = false;
                break;
            }
        }
        
        // if string meets requirements
        if (flag == true)
        {
            printf("%s\n", string);
        }
        flag = true;
    }
    return 0;
}