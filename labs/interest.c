#include <stdio.h>

// Написать функцию, удаляющую лидирующие и заключительные пробелы и символы табуляции.

int stringlength(char *str)
{
    int i = 0, length = 0;
    while (str[i] != '\0')
    {
        i++;
        length ++;
    }

    return length;
}

char* delSpacesnTabs(char *str)
{
    int len = stringlength(str);

    int start = 0;
    while (str[start] == ' ' || str[start] == '\t')
    {
        start++;
    }
    
    int end = len - 1;
    while ((end >= 0) && (str[end] == ' ' || str[end] == '\t'))
    {
        end--;
    }
    
    for (int i = 0; start + i <= end ; i++)
    {
        str[i] = str[start + i];
    }

    str[end - start + 1] = '\0';
    
    return str;
}

int main()
{
    char str[] = "\t    hello world    \t";
    printf("%s", delSpacesnTabs(str));
}