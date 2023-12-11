#include "func.h"
#include <stdlib.h>
#include <string.h>

char* dynamicarrayforstrings()
{
    size_t bufferSize = 10;

    char* str = (char*)malloc(bufferSize * sizeof(char));

    if (str == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }

    printf("Enter the string: ");

    char ch;
    size_t index = 0;

    while ((ch = getchar()) != '\n')
    {
        if (index == bufferSize - 1)
        {
            bufferSize *= 2;
            char* temp = (char*)realloc(str, bufferSize * sizeof(char));

            if (temp == NULL)
            {
                fprintf(stderr, "Memory reallocation error\n");
                free(str);
                return NULL;
            }

            str = temp;
        }
        str[index++] = ch;
    }

    str[index] = '\0';

    return str;
    // обязательно в конце main очищать память
}

void findMinLen(char* ptr, size_t len_string, int* minLen, int* startPos, int* endPos)
{
    int end = -1; // Устанавливаем end на -1 для учёта начала строки
    int start = 0;
    int min_len = 100000;
    int fin_start = 0;
    int fin_end = 0;

    for (int i = 0; i < len_string + 1; i++)
    {
        if (ptr[i] == ' ' || ptr[i] == '\0')
        {
            end = i - 1;
            if ((end - start) + 1 < min_len && end >= start) // Проверяем, является ли текущее слово самым коротким
            {
                min_len = (end - start) + 1;
                fin_start = start;
                fin_end = end;
            }
            start = i + 1;
        }
    }
    *minLen = min_len;
    *startPos = fin_start;
    *endPos = fin_end;
}




int main()
{
    int minLen, startPos, endPos;
    char* string_start = dynamicarrayforstrings();
    char* new_word = dynamicarrayforstrings();

    size_t len_string_start = strlen(string_start);
    size_t len_new_word = strlen(new_word);

    findMinLen(string_start, len_string_start, &minLen, &startPos, &endPos);

    char* answer = (char*)malloc((len_string_start - minLen + len_new_word + 1) * sizeof(char));

    for (int i = 0; i < startPos; i++)
        answer[i] = string_start[i];

    int j = 0;
    for (int i = startPos; i <= endPos; i++)
    {
        answer[i] = new_word[j];
        j++;
    }

    for (int i = endPos + 1; i <= len_string_start - minLen; i++)
        answer[i + len_new_word - 1] = string_start[i];

    answer[len_string_start - minLen + len_new_word] = '\0';

    puts(answer);

    free(string_start);
    free(answer);
    free(new_word);
    return 0;
}
