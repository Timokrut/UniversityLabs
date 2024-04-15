#include "header.h"

int main()
{
    test();

    char sentence[256];
    char delimiters[256];
    
    int index = 0;
    int c;

    printf("Enter your string: ");
    while ((c = getchar()) != '\n' && index < 256)
    {
        sentence[index] = c;
        index++;
    }
    sentence[index] = '\0';

    printf("Enter your delimiters: ");
    while ((c = getchar()) != '\n' && index < 256)
    {
        delimiters[index] = c;
        index++;
    }
    delimiters[index] = '\0';

    char* word2 = strtok(sentence, delimiters);

    while (word2 != NULL)
    {
        printf("%s\n", word2);
        word2 = strtok(NULL, delimiters);
    }
    return 0;
}
