#include <stdio.h>
#include "func.h"

int main(){
    int x;
    scanf("%d", &x);
    long long res = 11 * topow(x, 10) + 10 * topow(x, 9) + 9 * topow(x, 8) + 8 * topow(x, 7) + 7 * topow(x, 6) + 6 * topow(x, 5)+ 5 * topow(x, 4) + 4 * topow(x, 3) + 3 * topow(x, 2) + 2 * topow(x, 1) + 1 * topow(x, 0);
    printf("%d", res);
}