#include <stdbool.h>
#include "func.h"
#include <ctype.h>

// Ввести строку, вывести только слова, оканчивающиеся на согласную букву.

int main(){

    char string[100];
    char vowels[] = "aeiou";
    bool flag = true;

    
    while (true)
    {

        // enter a string
        scanf("%s", string);

        if (string[0] == '\0')
        break;
        // requirement to end program

        // index of last element
        int l_idx = len(string) - 1; 

        // checking if last symbol is vowel or not
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