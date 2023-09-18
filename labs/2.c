#include <stdio.h>
#include <string.h>

// Ввести строку, вывести только слова, оканчивающиеся на согласную букву.



int main(){
    
    char vowel[] = "aeiou";

    int n = strlen(vowel) - 1; // index of last element

    printf("%c",vowel[n]);
    
    return 0;
}