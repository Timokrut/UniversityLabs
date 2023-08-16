#include <stdio.h>

int main()
{
    int col, i = 0, ab = 1;
    scanf("%d", &col);
    int zap[col];
    for (i; i < col; i++)
    {
        zap[i] = ab++;
        printf("%d", zap[i]);
    }

    return 0;
}
