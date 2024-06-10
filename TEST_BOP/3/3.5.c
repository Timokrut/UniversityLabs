// Напишите программу, сложность которой O(n^3).

#include <stdio.h>

int main()
{
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            for (int k = 0; k < 100; k++)
                printf("%d", i + j + k);                        
    

    return 0;
}