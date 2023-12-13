# include <stdio.h>


double min(double a, double b)
{
    if (a < b)
    return a;
    else 
    return b;
}


int abs(int x)
{
    if (x < 0)
    x *= (-1);

    return x;
}


int topow(int x, int power)
{
    int result = 1;
    for (int i = 0; i <= power; i++)
    {
        result *= x;
    }
    return(result);
}


int my_strcmp(char *strg1, char *strg2)
{
    while( ( *strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2 )
    {
        strg1++;
        strg2++;
    }
        return *strg1 - *strg2;
}


int len(char* string)
{
    int length = 0;
    while (*string != '\0')
    {
        string++;
        length++;
    }

    return length;   
}

int isVowel(char c)
{
    char vowels[] = "aeiouyAEIOUY";
    for (int i = 0; i < 10; i++)
    {
        if (vowels[i] == c)
        return 1;
    }
    return 0;
}


char* my_strcat(char* dest, const char* src) {
    char* ptr = dest;
    // Находим конец dest
    while (*ptr != '\0') {
        ptr++;
    }
    // Копируем символы из src в конец dest
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    // Устанавливаем завершающий нулевой символ
    *ptr = '\0';
    return dest;
}

// void find_min_len(char* sentence, int* minLen, int* startPos, int* endPos)
// {
//     int string_length = len(sentence);

//     if (sentence[string_length - 1] == '\n')
//         sentence[string_length - 1] = '\0';

//     int word_start = 0;
//     int word_end = 0;
//     int word_min_length = 10000;
//     int cur_word_min_len;
//     int fin_start = 0;
//     int fin_end = 0;

//     for (int i = 0; i < string_length; i++)
//     {
//         if ((sentence[i] == ' ') || (sentence[i] == '\0'))
//         {
//             word_end = i - 1;

//             cur_word_min_len = word_end - word_start + 1;

//             word_min_length = min(word_min_length, (word_end - word_start) + 1);

//             if (cur_word_min_len <= word_min_length)
//             {
//                 fin_start = word_start;
//                 fin_end = word_end;
//             }
//             word_start = i + 1;
//         }
//     }
//     *minLen = word_min_length;
//     *startPos = fin_start;
//     *endPos = fin_end;
// }