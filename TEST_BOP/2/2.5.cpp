// Напишите оператор присваивания класса vector. Для работы с памятью
// используйте функции malloc и free.

#include <iostream>

class vector
{
    private:
        int* arr;
        size_t size;
        size_t capacity;
    public:
    vector():arr(nullptr), size(0), capacity(0) {};
    
    vector operator=(vector& other)
    {
        free(arr);
        this->capacity = other.capacity;
        this->size = other.size;
        arr = (int*)malloc(capacity * sizeof(int));

        for (int i = 0; i < size; i++)
            this->arr[i] = other.arr[i];        
        
        return *this;
    }        

};