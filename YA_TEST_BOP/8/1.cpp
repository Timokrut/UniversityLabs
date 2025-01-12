// функция получает на вход 2 массива. Функция дожна вывести результат поэтапного деления массива(тут типа mas1(i) всегда делится на mas2(i), 
// еcли в результате деления получается деление на ноль, функция должна выводить исключения при помощи std::exceptions.

#include <iostream>

template <typename T> void func(T* arr1, size_t size1, T* arr2, size_t size2) {
    for (size_t i = 0; i < std::min(size1, size2); i++) {
        if (arr2[i] == 0)
            throw std::exception();
        std::cout << arr1[i] / arr2[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    size_t size1 = 5;
    size_t size2 = 5;

    int arr1[size1] = {1, 2, 3, 4, 5};
    int arr2[size2] = {5, 4, 0, 2, 1};

    try {
        func(arr1, size1, arr2, size2);
    } catch (const std::exception& e) { 
        std::cerr << e.what();
    }
}