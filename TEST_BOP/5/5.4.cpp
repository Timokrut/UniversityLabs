// Создайте класс Figure с чисто виртуальным методом “подсчет площади фигуры”, 
// создайте класс Circle (круг) с переопределенным методом “подсчет площадь фигуры”
#include <iostream>

class Figure
{
    public:
        virtual float count_area() const = 0;    
};

class Circle : Figure
{
    private:
        float radius;
    public:
        float count_area() const override
        {
            return 3.14 * radius * radius;
        }
};