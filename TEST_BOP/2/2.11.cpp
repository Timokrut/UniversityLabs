// Напишите 2 разных примера вызова конструктора копий для класса vector

#include<iostream>

class vector
{
    private:
    int* arr;
    size_t size;
    size_t capacity;    

    public:
    vector():arr(nullptr), size(0), capacity(0) {};

    vector(vector &other) 
    {
        free(arr);
        this->size = other.size; 
        this->capacity = other.capacity;

        arr = (int*)malloc(sizeof(int) * capacity);
        
        for (int i = 0; i < size; i++)
            this->arr[i] = other.arr[i];
    }

    vector operator=(vector &other)
    {
        free(arr);
        this->size = other.size; 
        this->capacity = other.capacity;

        arr = (int*)malloc(sizeof(int) * capacity);
        
        for (int i = 0; i < size; i++)
            this->arr[i] = other.arr[i];

        return *this;    
    }
};