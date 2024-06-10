// Напишите реализацию методa push_back для класса vector с использованием malloc, realloc, free

#include <iostream>

class vector
{
    private: 
        int* arr;
        size_t size;
        size_t capacity;
    public:
        vector(): arr(nullptr), size(0), capacity(0) {};
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
                arr = (int*)malloc(sizeof(int) * capacity);
                arr[size] = number;
                size++;
            }
            // free 
            // else if (size >= capacity)
            // {
            //     capacity *= 2;
            //     int* new_arr = (int*)malloc(sizeof(int) * capacity);
            //     for (int i = 0; i < size; i++)
            //         new_arr[i] = arr[i];
            //     free(arr);

            //     arr = new_arr;
            //     arr[size] = number;
            //     size++;
            // }
            //realloc
            else if (size >= capacity)
            {
                capacity *= 2;
                int* new_arr = (int*)realloc(arr, capacity * sizeof(int));
                arr = new_arr;
                arr[size] = number;
                size++;
            }                     
        }   
        void print()
        {
            for (int i = 0; i < size; i++)
                std::cout<<arr[i]<<std::endl;            
        }
};

int main()
{
    vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);

    vec.print();

    return 0;
}