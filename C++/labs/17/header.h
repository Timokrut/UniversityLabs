#pragma once
#include <iostream>
#include <cstring>

template <typename T> void bubblesort(T* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j+1]);
        }
}


template <typename T> class Set 
{
    private:
        T* elements;           
        int size;                         
        int capacity;

    public:     
        Set(int _capacity) : size(0), capacity(_capacity) 
        {
            if (_capacity == 0)
                throw std::runtime_error("Emty Set");
            elements = new T[capacity];
        }

        ~Set() 
        {
            delete[] elements;
        }

        Set(const Set& other) : size(other.size), capacity(other.capacity) 
        {
            elements = new T[capacity];
            std::memcpy(elements, other.elements, size * sizeof(T));
        }

        Set& operator=(const Set& other) 
        {
            if (this == &other) 
                return *this;
            
            delete[] elements;
            size = other.size;
            capacity = other.capacity;
            elements = new T[capacity];
            
            std::memcpy(elements, other.elements, size * sizeof(T));
            return *this;
        }

        void resize(int newCapacity) 
        {
            T* newElements = new T[newCapacity];
            std::memcpy(newElements, elements, size * sizeof(T));
            delete[] elements;
            elements = newElements;
            capacity = newCapacity;
        }

        void add(T num) 
        {
            if (!contains(num)) 
            {
                if (size == capacity) 
                    resize(2 * capacity);
                elements[size++] = num;
                bubblesort(elements, size);
            }
        }

        void erase(T num) 
        {
            for (int i = 0; i < size; i++) 
                if (elements[i] == num) 
                {
                    for (int j = i; j < size - 1; j++) 
                        elements[j] = elements[j + 1];
                    size--;
                    break;
                }
        }

        bool contains(T num)  
        {
            for (int i = 0; i < size; i++) 
                if (elements[i] == num) 
                    return true;
            return false;
        }

        int getSize()
        {
            return size;
        }

        void clear()
        {
            delete[] elements;
            elements = new T(capacity);
            size = 0;
        }

        friend std::ostream& operator<<(std::ostream& os, const Set<T>& set) 
        {
            os << "{";
            for (int i = 0; i < set.size; i++) 
            {
                if (i == set.size - 1)
                    os << set.elements[i];
                else
                    os << set.elements[i] << ", ";
            }
            os << "}";
            return os;
        }
};

