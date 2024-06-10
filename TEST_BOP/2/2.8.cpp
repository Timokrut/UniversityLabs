// Напишите определение конструктора и деструктора для vector
#include <iostream>

class vector
{
    private:
    int* arr;
    size_t size;
    size_t capacity;
    public:
    vector():arr(nullptr), size(0), capacity(0) {};
    
    ~vector() 
    {
        delete[] arr;
    }
};