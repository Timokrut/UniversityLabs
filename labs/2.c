#include <stdbool.h>
#include "func.h"
#include <ctype.h>

// Ввести строку, вывести только слова, оканчивающиеся на согласную букву.

int main(){

    char string[100];
    char vowels[] = "aeiou";
    bool flag = true;

    printf("enter '!' to end program\n");
    
    while (true)
    {

        // enter a string
        scanf("%s", string);

        // requirement to end program
        if (my_strcmp(string, "!") == 0)
        break;

        // index of last element
        int l_idx = len(string) - 1; 

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