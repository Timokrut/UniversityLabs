#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000

// availibale functions:
// printf, scanf, getchar
// gets, fgets, malloc, free, fopen, fclos



char *readFile(FILE *file);

char *merge_arrays(char *string1, char *string2, char *string3);

void sort_LtH_bylen(char* arr)
{
    int length = 1;

    for (int i = 0; arr[i] != '\0'; i++)
        if (arr[i] == ' ')
            length++;    

    char* temp;
    for (int i = 0; i < length - 1; i++)
        for (int j = i + 1; j < length; j++)
            if (strlen(arr[i]) > strlen(arr[j]))
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}


int main()
{
    FILE *file1;
    FILE *file2;
    FILE *file3;
    char *string1;
    char *string2;
    char *string3;
    char *fin_array;

    file1 = fopen("file1.txt", "r");
    string1 = readFile(file1);

    file2 = fopen("file2.txt", "r");
    string2 = readFile(file2);

    file3 = fopen("file3.txt", "r");
    string3 = readFile(file3);

    fin_array = merge_arrays(string1, string2, string3);

    sort_LtH_bylen(fin_array);

    printf("%s", fin_array);

    free(string1);
    free(string2);
    free(string3);
    free(fin_array);
    return 0;
}

char *readFile(FILE *file)
{
    char *string = (char *)malloc(LEN * sizeof(char));

    fgets(string, LEN * sizeof(char), file);

    return string;
}

char *merge_arrays(char *string1, char *string2, char *string3)
{
    int len1; for (len1 = 0; string1[len1] != '\0'; len1++);
    int len2; for (len2 = 0; string2[len2] != '\0'; len2++);
    int len3; for (len3 = 0; string3[len3] != '\0'; len3++);
    int fin_size = 0;

    fin_size = len1 + len2 + len3;

    char *fin_array = (char*)malloc(fin_size * sizeof(char));

    int u = 0;

    for (int i = 0; i < len1; i++)
    {
        fin_array[u] = string1[i];
        u++;
    }
    for (int i = 0; i < len2; i++)
    {
        fin_array[u] = string2[i];
        u++;
    }
    for (int i = 0; i < len3; i++)
    {
        fin_array[u] = string3[i];
        u++;
    }

    return fin_array;
}
