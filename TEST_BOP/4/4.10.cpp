// Дан класс, описывающий прямоугольник (ширина, высота). Перегрузите оператор < для сравнения объектов этих классов по значению периметра

#include <iostream>

class Rectangle
{
    private:
        float width;
        float length;
    public:
        Rectangle(): width(1.0), length(1.0) {};
        Rectangle(int wid, int len): width(wid), length(len) {};
        
        bool operator<(Rectangle &other)
        {
            return 2 * (this->length + this->width) < 2 * (other.length + other.width);
        }
};

int main()
{
    Rectangle r1(1.0, 5.0);
    Rectangle r2;

    std::cout<<(r2 < r1)<<std::endl;
}