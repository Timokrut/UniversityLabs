// Написать шаблонную Функцию, которая берет на вход два массива src1 и src2 шаблонного типа и их длины. 
// Если длины массивов не равны, то функция бросает исключение типа std::exception. Если длины массивов равны, 
// то функция записывает в src2 поэлементный максимум элементов обоих массивов.

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T> void func(T* src1, size_t size1, T* src2, size_t size2) {
    if (size1 != size2) 
        throw std::exception();

    for (size_t i = 0; i < size1; i++)
        src2[i] = std::max(src1[i], src2[i]);
}

int main() {
    try {
        size_t size1 = 5;
        size_t size2 = 6;
        int array1[size1] = {1, 2, 3, 4, 5};
        int array2[size2] = {6, 5, 4, 3, 2, 1};

        func(array1, size1, array2, size2);

        for (size_t i = 0; i < size1; i++)
            std::cout << array2[i] << " ";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}