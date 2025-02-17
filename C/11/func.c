#include "header.h"

char* my_strtok(char* str, const char* delim)
{
    static char* next;

    if (str)
    {
        next = str;
        while (*next && strchr(delim, *next))
        {
            *next++ = '\0';
        }

    }

    if (!*next)
        str = NULL;
    else {
        str = next;
        while (*next && !strchr(delim, *next))
        {
            next++;
        }

        while (*next && strchr(delim, *next))
        {
            *next++ = '\0';
        }
    }
    return str;
}

void test()
{
    system("clear");
    printf("  _______________________\n");
    printf(" /_  __/ ____/ ___/_  __/\n");
    printf("  / / / __/  |__ | / /   \n");
    printf(" / / / /___ ___/ // /    \n");
    printf("/_/ /_____//____//_/     \n");

    char sentence[] = "Hello Timofey, how are u doing today. -OK";
    const char delimiters[] = " ,.";
    char* word1 = strtok(sentence, delimiters);
    char* word2 = my_strtok(sentence, delimiters);
    while (word1 != NULL && word2 != NULL)
    {
        assert(strcmp(word1, word2) == 0);
        word1 = strtok(NULL, delimiters);
        word2 = my_strtok(NULL, delimiters);
    }

    char sentence2[] = "This is - www.google.com - website";
    const char delimiters2[] = " -.";
    word1 = strtok(sentence2, delimiters2);
    word2 = my_strtok(sentence2, delimiters2);
    while (word1 != NULL && word2 != NULL)
    {
        assert(strcmp(word1, word2) == 0);
        word1 = strtok(NULL, delimiters2);
        word2 = my_strtok(NULL, delimiters2);
    }

    char sentence3[] = "one + two * (three - four)!";
    const char delimiters3[] = "!+-*()";
    word1 = strtok(sentence3, delimiters3);
    word2 = my_strtok(sentence3, delimiters3);
    while (word1 != NULL && word2 != NULL)
    {
        assert(strcmp(word1, word2) == 0);
        word1 = strtok(NULL, delimiters3);
        word2 = my_strtok(NULL, delimiters3);
    }
    printf("Tests passed successfully\n");
    printf("Press enter for manual working");
    getchar();
    system("clear");
}