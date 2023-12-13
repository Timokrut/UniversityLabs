#include "func.h"
#include <stdlib.h>

// Ввести строку и слово. Вставить введенное слово вместо самого короткого слова в строке.

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

int custom_strlen(const char* str)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void custom_strcpy(char* dest, const char* src)
{
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void func(char* sentence, int* minLen, int* startPos, int* endPos, int* sentence_length)
{
    int string_length = len(sentence);
    sentence[string_length - 1] = '\0';
    int cur_length = 0;
    int startW = 0;
    int endW = 0;
    int len_arr = 0;

    for (int i = 0; i < string_length; i++) if (sentence[i] == ' ') len_arr++;
    len_arr++;
    
    int lengthes[len_arr];
    int indexes[len_arr][2];
    int k = 0;

    for (int i = 0; i < string_length; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\0')
        {   
            endW = i - 1;
            cur_length = endW - startW + 1;
            lengthes[k] = cur_length;
            indexes[k][0] = startW;
            indexes[k][1] = endW;
            startW = i + 1;
            k++;
        }
    }

    int max_diff = -1;
    int max_index = 0;
    for (int i = 0; i < len_arr - 1; i++)
    {
        max_diff = max(max_diff, abs(lengthes[i] - lengthes[i + 1]));
        if (max_diff == abs(lengthes[i] - lengthes[i + 1]))
            max_index = i;
    }
    
    // NOW I NEED TO COMPARE FIND min length
    int for_return = max_index;
    if (lengthes[max_index] < lengthes[max_index + 1])
    {
    *minLen = lengthes[max_index];
    *startPos = indexes[max_index][0];
    *endPos = indexes[max_index][1];
    *sentence_length = string_length;
    }
    else
    {
    *minLen = lengthes[max_index + 1];
    *startPos = indexes[max_index + 1][0];
    *endPos = indexes[max_index + 1][1];
    *sentence_length = string_length;
    }
}


char* replace_shortest_word(char* sentence, char* new_word)
{
    int new_word_len = len(new_word);
    int minLen;
    int startPos;
    int endPos;
    int sentence_length;
    func(sentence, &minLen, &startPos, &endPos, &sentence_length);

    int new_sentence_len = sentence_length - 1 + new_word_len - minLen;
    char* result = (char*)malloc((new_sentence_len + 1) * sizeof(char));

    if (result == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }
    int k = 0;
    for (int i = 0; i < startPos; i++)
    {
        result[i] = sentence[i];
        k++;
    }

    int j = 0;
    for (int i = startPos; j < new_word_len; i++)
    {
        result[i] = new_word[j];
        j++;
    }
    
    j += k;

    for (int i = endPos + 1; i < sentence_length; i++)
    {
        result[j] = sentence[i];
        j++;
    }
    return result;
}

int main()
{
    char input_sentence[1000];
    char new_word[100];

    printf("Enter a sentence: ");
    fgets(input_sentence, sizeof(input_sentence), stdin);
    swap_spaces(input_sentence);

    printf("Input a word: ");
    scanf("%s", new_word);

    char* result = replace_shortest_word(input_sentence, new_word);
    if (result != NULL) {
        printf("Result: %s\n", result);
        free(result);
    }
    return 0;
}