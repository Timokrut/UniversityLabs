#include <stdio.h>

struct Car
{
    int speed;
    char name[50];
    float weight;
};


int main(){
    struct Car BMW = {170, "BMW M8", 2500.00f};
    struct Car Mercedes = {200, "Mercedes Maybach", 3000.00f};
    struct Car Audi = {230, "Audi A8", 1700.00f};

    printf("Автомобиль %s обладает скоростью: %d\n", BMW.name, BMW.speed);
    printf("Автомобиль %s обладает скоростью: %d\n", Mercedes.name, Mercedes.speed);
    printf("Автомобиль %s обладает скоростью: %d\n", Audi.name, Audi.speed);

   return 0; 
}