// Выразите оператор bool operator >= (BigInt& a, BigInt& b) через операторы < и =
#include <iostream>

class BigInt
{
    private:
        // data
    public:
        bool operator<(BigInt &other)
        {
            // 
        }

        friend bool operator>=(BigInt &a, BigInt &b)
        {
            return !(a < b);
        }    
        
        //alternative
        bool operator>=(BigInt &other)
        {
            return !(*this < other);
        }

};