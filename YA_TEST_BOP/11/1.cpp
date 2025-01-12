// Дана  шаблонная функция T f(const T& a), которая может бросить исключение типа std::exception. Написать шаблонную функцию, которая берет на вход 
// массив srс и его длину и заменяет все элементы src[i] на f(src[i]). Если f бросила исключение на каком-то элементе, то необходимо, 
// поймать и вывести исключение типа std::runtime_exception.

#include <iostream>

template <typename T> T f(const T& a) { 
    if (a < 0) {
        throw std::exception();
    }
    return a*2;
}

template <typename T> void func(T* src, size_t size) {
    for (size_t i = 0; i < size; i++) {
        try {
            src[i] = f(src[i]);
        } catch (const std::exception& e) {
            throw std::exception();
        }
    }
}

int main() {
    size_t size = 5;
    int arr[size] = {1, 2, -1, 4, 5};
    func(arr, size);

    for (auto el : arr) {
        std::cout << el << std::endl;
    }
}