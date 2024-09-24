#include <iostream>
// Realization of set on templates
// insert
// erase
// exception on empty
// bool find(const &T value)
// size
// clear
// operator<< - cout

// template<typename T>


// #include "header.h"
#include <algorithm> // for sort (check equality)
#include <cstring> // for memcpy

template <typename T> class Set 
{
    private:
        T* elements;           
        int size;                         
        int capacity;

    public:      
        Set() : size(0), capacity(10) {
            elements = new T[capacity];
        }

        ~Set() {
            delete[] elements;
        }

        Set(const Set& other) : size(other.size), capacity(other.capacity) {
            elements = new T[capacity];
            std::memcpy(elements, other.elements, size * sizeof(T));
        }

        Set& operator=(const Set& other) {
            if (this == &other) return *this;
            delete[] elements;
            size = other.size;
            capacity = other.capacity;
            elements = new T[capacity];
            std::memcpy(elements, other.elements, size * sizeof(T));
            return *this;
        }

        void resize(int newCapacity) {
            T* newElements = new T[newCapacity];
            std::memcpy(newElements, elements, size * sizeof(T));
            delete[] elements;
            elements = newElements;
            capacity = newCapacity;
        }

        void add(T num) {
            if (!contains(num)) {
                if (size == capacity) {
                    resize(2 * capacity);
                }
                elements[size++] = num;
            }
        }

        void remove(T num) {
            for (int i = 0; i < size; ++i) 
                if (elements[i] == num) {
                    for (int j = i; j < size - 1; ++j) 
                        elements[j] = elements[j + 1];
                    size--;
                    break;
                }
        }

        bool contains(T num) const {
            for (int i = 0; i < size; ++i) 
                if (elements[i] == num) 
                    return true;
            return false;
        }

        void print() const {
            std::cout << "{";
            for (int i = 0; i < size; i++) {
                if (i == (size - 1)) {
                    std::cout << elements[i];
                    break;
                }
                std::cout << elements[i] << ", ";
            }
            std::cout << "}" << std::endl;
        }

        int getSize() const {
            return size;
        }

        friend std::ostream& operator<<(std::ostream& os, const Set<T>& set) {
            os << "{";
            for (int i = 0; i < set.size; ++i) {
                if (i == set.size - 1)
                    os << set.elements[i];
                else
                    os << set.elements[i] << ", ";
            }
            os << "}";
            return os;
        }
};






int main()
{
    Set<int> i_set;
    i_set.add(1);
    i_set.add(2);
    i_set.add(3);

    Set<float> f_set;
    f_set.add(1.5);
    f_set.add(2.5);
    f_set.add(3.5);

    i_set.print();
    f_set.print();
}