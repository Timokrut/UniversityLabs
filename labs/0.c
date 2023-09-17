#include <stdio.h>


int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    while (b == 0)
    {
        printf("second value should't be 0\n");
            scanf("%d", &b);
        
    }
    printf("result is %d", c % b);
    return 0; 
}