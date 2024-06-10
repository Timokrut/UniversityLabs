// Даны два класса, связанные наследованием: Figure (координата x, координата y) и Circle (координата x, координата радиус) 
// Вычислите размер объекта класса Circle в байтах

#include <iostream>

class Figure {
public:
    int x;
    int y;
};

class Circle : public Figure {
public:
    int radius;
};

int main() {
    std::cout << "Size of Circle: " << sizeof(Circle) << " bytes" << std::endl;
    return 0;
}
