// Дана шаблонная функция Т f(const T& a), которая может бросить исключение типа std::exception. 
// Написать шаблонную функцию, которая берет на вход массив src и его длину и заменяет все элементы src[i] на f(src[i]). 
// Если f бросила исключение на каком-то элементе, то необходимо остановить исполнение и бросить новое исключение типа std::runtime_exception.

#include <iostream>

#include <iostream>
#include <stdexcept>

template <typename T> T f(const T& a) {
    if (a < 0)
        throw std::exception();
    return a + 1;    
}

template <typename T> void func(T* src, size_t size) {
    for (size_t i = 0; i < size; i++) { 
        try {
            src[i] = f(src[i]);
        } catch (const std::exception& e) {
            std::cerr << "Negative number at index " << i << std::endl;
            throw std::runtime_exception(); // not found execption
        }
    }
}

int main() {
    size_t size = 5;
    int arr1[size] = {1, 2, -3, 4, 5};

    func(arr1, size);

    for (size_t i = 0; i < size; i++)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;
}