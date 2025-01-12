// Написать шаблонную функцию, которая берет на вход src1, src2, result и три их длинны. 
// Функция копирует в массив result сначала массив src1, а за ним массив src2. 
// Если длинны массива result не хватает, то функция бросает исключение std::exception

#include <iostream>

template <typename T> void func(T* arr1, size_t size1, T* arr2, size_t size2, T* arr3, size_t size3) { 
    if ((size1 + size2) > size3) {
        throw std::exception();
    }
    std::copy(arr1, arr1 + size1, arr3);
    std::copy(arr2, arr2 + size2, arr3 + size1);
}

int main() {
    size_t size1 = 3;
    size_t size2 = 4;
    size_t size3 = 7;

    int arr1[size1] = {1, 2, 3};
    int arr2[size2] = {4, 5, 6, 7};
    int arr3[size3] = {0};

    func(arr1, size1, arr2, size2, arr3, size3);

    for (auto el : arr3) {
        std::cout << el << " ";
    }
}