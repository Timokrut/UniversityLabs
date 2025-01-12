// Написать программу, которая на вход берет три массива шаблонного типа src1, src2 и result и три их длины. Функция копирует в массив result тот массив src, 
// который имеет максимальную длину. Если длины массива result не хватает, то функция бросает исключение типа std:: exception.

#include <iostream>


template <typename T> void func(T* src1, size_t size1, T* src2, size_t size2, T* result, size_t size3) {
    const T* max_array = nullptr;
    size_t max_length = 0;

    if (size1 >= size2) {
        max_array = src1;
        max_length = size1;
    } else {
        max_array = src2;
        max_length = size2;
    }

    if (max_length > size3) 
        throw std::exception();

    std::copy(max_array, max_array + max_length, result);   
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