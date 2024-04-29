#include "header.h"

int main()
{
    test();

    char sentence[256] ;
    char delimiters[256];
    
    int index = 0;
    int c;

    printf("Enter your string: ");
    fgets(sentence, 256, stdin);

    printf("Enter your delimiters: "); 
    fgets(delimiters, 256, stdin);

    char* word2 = my_strtok(sentence, delimiters);

    create_file(word2);


    while (word2 != NULL)
    {
        printf("%s\n", word2);
        word2 = my_strtok(NULL, delimiters);
        
        if (word2 != NULL)
            create_file(word2);
    }


    return 0;
}
