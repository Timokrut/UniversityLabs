// Перегрузка на примере swap

#include <iostream>
#include <string> 

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void swap(double &a, double &b)
{
    double c = a;
    a = b;
    b = c; 
}

int main()
{
    int int_a = 5;
    int int_b = 3;

    swap(int_a, int_b);

    std::cout<<int_a << " " << int_b << std::endl;

    double double_a = 5.2;
    double double_b = 3.2;

    swap(double_a, double_b);
    std::cout<<double_a << " " << double_b << std::endl;

    return 0;
}