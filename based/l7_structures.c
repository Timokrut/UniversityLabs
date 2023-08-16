#include <stdio.h>

struct Car
{
    int speed;
    char name[50];
    float weight;
};


int main(){
    struct Car BMW;
    BMW.speed = 170; 
    strcpy(BMW.name, "BMW M8");
    BMW.weight = 2500.00f;
        
    struct Car Mercedes = {200, "Mercedes Maybach", 3000.00f};
    printf("Автомобиль %s обладает скоростью: %d\n", BMW.name, BMW.speed);
    printf("Автомобиль %s обладает скоростью: %d\n", Mercedes.name, Mercedes.speed);
    
//gfh

   return 0; 
}