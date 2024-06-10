// Выразите оператор bool operator == (BigInt &a, BigInt &b) через оператор “<”

#include <iostream>

class BigInt
{
    private:
        // 
    public:
        bool operator<(BigInt &other)
        {
            // 
        }
        bool operator==(BigInt &other)
        {
            return !(*this < other) && !(other < *this);
        }
};