#include <stdio.h>
#include <string.h>

int main(){
    
    char str[] = "Hello";
    printf("%s\n", str);
    
    int length;
    length = strlen(str);

    printf("length of your string is %d", length);
    return 0;
}