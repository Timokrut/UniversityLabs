// Перегрузите оператор << для класса, описывающего дробь (числитель, знаменатель).
#include <iostream>

class Fraction
{
    private:
        size_t numerator;
        size_t denumerator;

    public:
    Fraction():numerator(1), denumerator(2) {};

    friend std::ostream& operator<<(std::ostream& os, const Fraction &number)
    {
        os << "Numerator: " << number.numerator << " Denumerator" << number.denumerator;
        return os;
    }     
};