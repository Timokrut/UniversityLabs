// Написать шаблонную функцию, которая берет на вход три шаблонных массива src1, src2, result и три их длины. 
// Функция копирует в массив result сначала массив src1, а за ним массив src2. Если длины массива result не хватает, 
// то функция бросает исключение типа std::exception.


#include <iostream>


template <typename T> void func(T* src1, size_t size1, T* src2, size_t size2, T* result, size_t size3) {
    if ((size1 + size2) > size3)
        throw std::exception();

    size_t i = 0;
    for (i = 0; i < size1; i++) {
        result[i] = src1[i];
    }

    for (int j = 0; j < size2; j++) {
        result[i] = src2[j];
        i++;
    }
}


int main() {
    int size1 = 5; 
    int size2 = 4;
    int size3 = 9;
    int arr1[size1] = {1, 2, 3, 4, 5};
    int arr2[size2] = {1, 2, 3, 4};
    int arr3[size3] = {0};

    func(arr1, size1, arr2, size2, arr3, size3);

    for (size_t i = 0; i < size3; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;
}