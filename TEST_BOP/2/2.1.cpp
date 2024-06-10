// Напишите реализацию метода push_back для класса vector с использованием new и delete.
#include <iostream>

class vector
{
    private:
        int* arr;
        size_t size;
        size_t capacity;
    public:
        vector(): arr(nullptr), size(0), capacity(0){}; // constructor
        void push_back(int number)
        {
            if (size < capacity)
            {
                arr[size] = number;
                size++;
            }
            else if (size == 0)
            {
                capacity = 1;
                arr = new int[capacity];
                arr[0] = number;
                size++;
            }
            else if (size >= capacity)
            {
                capacity *= 2;
                int* new_arr = new int[capacity];
                for (int i = 0; i < size; i++)
                    new_arr[i] = arr[i];
                delete arr;

                arr = new_arr;
                arr[size] = number;
                size++;                    
            }
        }
        void print_array()
        {
            for (int i = 0; i < size; i++)
                std::cout<<arr[i]<<std::endl;
        }
};

int main()
{
    vector vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);

    vec.print_array();

    return 0;
}