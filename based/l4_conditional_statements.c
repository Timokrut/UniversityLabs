#include <stdio.h>
#include <stdbool.h>

int main(){
    int x;
    printf("Какая у тебя оценка?\n");
    scanf("%d", &x);
    
    // INFO

    // if x == 5 || x == 4 (|| == or, u can spam it: x || y || z || etc.)
    // if x < 10 && x > 3(&& == and, u also can spam it )


    // IF | ELSE BLOCK

    if(x == 5){
        printf("Круто. %d - отличная оценка !\n", x);
    }
    else if(x == 4){
        printf("Неплохо. %d - хорошая оценка!\n", x);
    } 
    else if(x == 3){
        printf("Пойдет. %d - не хорошо и не плохо\n", x);
    }
    else{
        printf("Нужно тренироваться!\n");
    }

    // BOOL BLOCK

    bool isCool = true;
    int y = 0;
    printf("%d", isCool + y);


    // SWITCH CASE BLOCK


    switch (x)
    {
    case 1:
        printf("Нужно тренироваться!");
        break;
    case 2:
        printf("Нужно тренироваться!");
        break;        
    case 3:
        printf("Пойдет. 3 - не хорошо и не плохо");
        break;        
    case 4:
        printf("Неплохо. 4 - хорошая оценка!");
        break;        
    case 5:
        printf("Круто. %d - отличная оценка !");
        break;             
    
    // works like "else" 

    default:
        printf("Такой оценки не существует!");
    }

    return 0;
}