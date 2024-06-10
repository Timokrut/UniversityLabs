// Написать алгоритм со сложности O(n ^ 4)

#include <stdio.h>

int main()
{
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            for (int k = 0; k < 100; k++)
                for (int l = 0; l < 100; l++)
                    printf("%d", i + j + k + l);                        

    return 0;
}