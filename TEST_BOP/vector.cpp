#include <iostream>

class Vector
{
    private:
        int* arr;
        size_t size;
        size_t capacity;
    public:
        Vector(): arr(nullptr), size(0), capacity(0) {};
        Vector(int* data, int actual, int maximum): arr(data), size(actual), capacity(maximum) {}; 

        ~Vector()
        {
            delete[] arr;
        }

        Vector(Vector &other)
        {
            delete[] arr;

            this->size = other.size;
            this->capacity = other.capacity;

            arr = new int[capacity];

            for (int i = 0; i < size; i++)
                this->arr[i] = other.arr[i];            
        }

        Vector operator=(Vector &other)
        {
            delete[] arr;

            this->size = other.size;
            this->capacity = other.capacity;
            arr = new int[capacity];

            for (int i = 0; i < size; i++)
                this->arr[i] = other.arr[i];

            return *this;
        }

        void push_back(int number)
        {
            if (size < capacity)
                arr[size++] = number;

            else if (size == 0)
            {
                capacity = 1;
                arr = new int[capacity];
                arr[size++] = number;
            }
            else if (size >= capacity)
            {
                capacity *= 2;
                int* new_arr = new int[capacity];
                for (int i = 0; i < size; i++)
                    new_arr[i] = arr[i];

                delete[] arr;
                arr = new_arr;

                arr[size++] = number;                                    
            }
        }

        void set(int index, int value)
        {
            if (index < 0 || index >= size) 
                throw std::out_of_range("Index out of range");
            arr[index] = value;
        }

        int get(int index)
        {
            if (index < 0 || index >= size)
                throw std::out_of_range("Index out of range");
            return arr[index];
        }

        void insert(int index, int value)
        {
            int i = 0;
            if (index < 0 || index >= size)
                throw std::out_of_range("Index out of range");
            push_back(0);
            for (int i = size - 1; i > index ; i--)
                arr[i] = arr[i - 1];

            arr[i] = value;                          
        }

        void erase(int index)
        {
            if (index < 0 || index >= size)
                throw std::out_of_range("Index out of range");
            for (int i = index; i < size - 1; i++)
                arr[i] = arr[i + 1];
            size--;            
        }

        int find(int number)
        {
            for (int i = 0; i < size; i++)
                if (arr[i] == number)
                    return i;
            return -1; // not found        
        }

        void shrink_to_fit()
        {
            if (capacity != size)
            {
                capacity = size;
                int* new_arr = new int[capacity];
                for (int i = 0; i < size; i++)
                    new_arr[i] = arr[i];

                delete[] arr;
                arr = new_arr;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, Vector &vector)
        {
            os << "[ ";
            for (int i = 0; i < vector.size; i++)
            {
                os << vector.arr[i];
                os << " ";
            }
            os << "]";
            return os;
        }
        
        void print()
        {
            for (int i = 0; i < size; i++)
                printf("%d ", arr[i]);
        }
};

int main()
{
    Vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::cout<<vec;

    return 0;
}