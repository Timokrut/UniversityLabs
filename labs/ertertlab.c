// Дан двумерный массив.Определить количество элементов массива с различными значениями.
#include <stdio.h>

int main()
{
    int columns, rows, temp, counter = 1;
    scanf("%d", &columns);
    scanf("%d", &rows);

    int array[columns * rows];
    for (int i = 0; i < (columns * rows); i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < (columns * rows); i++)
        for (int j = 0; j < (columns * rows) - 1 - i; j++)
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }

    for (int i = 0; i < (columns * rows) - 1; i++)
    {
        if (array[i] != array[i + 1])
            counter++;
    }
    printf("%d", counter);

    return 0;
}