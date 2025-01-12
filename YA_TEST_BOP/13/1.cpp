// Дана шаблонная функция T f(const T& a), которая может бросить std::exception. 
// Написать шаблонную функцию, которая берет на вход массив src и его длинну и заменяет все элементы src[i] на f(src[i]). 
// Если f бросила исключение, то надо заменить его на 0

#include <iostream>

template <typename T> T f(const T& a) {
    if (a < 0) {
        throw std::exception();
    }
    return a * 2;
}


template <typename T> void func(T* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        try {
            arr[i] = f(arr[i]);
        } catch (const std::exception& e) {
            arr[i] = 0;
        }
    }  
}

int main() {
    size_t size = 5;
    int arr[size] = {1, 2, 3, -1, 5};

    func(arr, size);
    for (auto el : arr) {
        std::cout << el << " ";
    }
}