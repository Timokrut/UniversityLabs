// Написать два примера перегруза конструктора для класса вектор

#include <iostream>

class vector
{
    private:
    int* arr;
    size_t size;
    size_t capacity;

    public:
    vector():arr(nullptr), size(0), capacity(0) {};
    vector(int* data, int actual, int maximum):arr(nullptr), size(actual), capacity(maximum) {};
};
