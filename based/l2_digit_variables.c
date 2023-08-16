#include <stdio.h>
#include <stdbool.h>

int main(){

    // INTEGERS
    
    // can't change after init(try to use CAPSLOCK in naming)  
    const int R = 23;
    // mistake -> R = 1;

    // range [-32768, 32768]
    short s = 32;
    
    // range [0, 64000]
    unsigned short v = 22;

    // range [-2mil, 2mil]
    int a = 14;
    
    // range [0, 4mil]
    unsigned int mur = -1;

    // [-4mil, 4mil]
    long g = 123123;

    // if long -> add L in print to all types of digits // chars (except short)
    printf("%Ld\n", g);


    // [0, 16mil]
    unsigned long g2 = 222222222;

    // 2 times bigger than long 
    long long g3 = 22222222222;

    // VEEEEEEEERY BIG NO NEGATIVES
    unsigned long long g4 = 123123;


    // FLOAT

    // can't be unsigned !!! 
    float a1 = 4.52323f;
    
    // bigger range
    double a2 = 3.1234567123f;

    // bigger then bigger range
    long double a3 = 1.12312312312313f;


    // E.G
    float b1 = 1.23f, b2 = 4.234f, result;
    result = b1 / b2;
    // to print float - %f
    // to make as much digits after comma as u want use .x after %
    printf("b1 /  b2 = %.2f\n", result);


    //CHAR


    // not in " ", len = 1
    char sym = '@';
    printf ("%c\n", sym);


    //BOOLEAN


    // need libary -> <stdbool.h>
    bool isCool = true;


    // INPUT VARIABLES

    int z, r, c;
    scanf("%d", &z);
    scanf("%d", &r);
    scanf("%d", &c);
    printf("Сумма трех чисел - %d\n", z + r+ c);


    // E.G
    int x = 5, y = 11, res;

    res += 12;
    y ++;
    x --;

    printf("variable: %d + %d = %d", res, x, res + x);
    return 0;
}