#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Ввести строку, вывести только слова, оканчивающиеся на согласную букву.

int main(){

    char string[100];
    char vowel[] = "aeiou";
    bool flag = true;
    
    while (true)
    {
        scanf("%s", &string);
        int l = strlen(string) - 1; // index of last element
        for (int i = 0; 4; i++)
        {
            if (vowel[i] != l)
            {
                // add to answer
                // break;
            }
            else
            {
                continue;
            }
            

        }
        


    }
    
    // разделение строки по пробелам

    // опреде


    return 0;
}