// Приведите объявление двух классов, связанных наследованием:
// Figure (координата x, координата y) и Rectangle (координата x, координата y, ширина, высота)
#include <iostream>

class Figure
{
    private:
        int x;
        int y;
};

class Rectangle : Figure
{
    private:
        int width;
        int height;
};

int main()
{
    std::cout<< sizeof(Figure)<<std::endl;
    std::cout<< sizeof(Rectangle)<<std::endl;

    return 0;
}