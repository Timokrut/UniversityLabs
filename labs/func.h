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

    if(*strg1 == *strg2)
    {
        return 0; // strings are identical
    }

    else
    {
        return *strg1 - *strg2;
    }
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