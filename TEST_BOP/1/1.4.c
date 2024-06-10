// Напишите фрагмент программы, в котором из строк "Tom", "And", "Jerry", записанных в разных массивах, формируется массив "TomAndJerry". 
// Используйте функции strcpy и strcat

#include <stdio.h>
#include <string.h>

int main()
{
    char string1[] = "Tom";
    char string2[] = "And"; 
    char string3[] = "Jerry";

    char result[12];

    strcpy(result, string1);
    strcat(result, string2);
    strcat(result, string3);

    printf("%s", result);

    return 0;
}