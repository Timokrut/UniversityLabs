// Написать фрагмент программы с функцией strcpy
// дан массив “Hello, world” слово “world” должно быть перенесено в другой массив

#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[] = "Hello, world";
    char word[] = "world";

    char new_sentence[6];
    char* in_string;

    in_string = strstr(sentence, word);
    strcpy(new_sentence, in_string); 

    printf("%s", new_sentence);
    return 0;
}