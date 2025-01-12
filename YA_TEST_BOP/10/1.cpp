// Написать шабонную функцию, которая берет на вход три массива шаблонного типа src1, src2, result и три их длинны, 
// Функция копирует в массив result тот массив srcкоторый имеет максимальную длинну. 
// Если длинны масива result не хватает, то функция бросает std::exception

#include <iostream>

template <typename T> void func(T* src1, size_t size1, T* src2, size_t size2, T* result, size_t size3) {
    size_t max_size = 0;
    T* max_arr = nullptr;

    if (size1 >= size2) {
        max_size = size1;
        max_arr = src1;
    } else {
        max_arr = src2;
        max_size = size2;
    }

    if (max_size > size3) {
        throw std::exception();
    }

    std::copy(max_arr, max_arr + max_size, result);
}


int main() {
    size_t size1 = 5;
    size_t size2 = 6;
    size_t size3 = 7;
    int arr1[size1] = {1, 2, 3, 4, 5};
    int arr2[size2] = {1, 2, 3, 4, 5, 6};
    int arr3[size3] = {0};

    func(arr1, size1, arr2, size2, arr3, size3);

    for (auto el : arr3) {
        std::cout << el << " ";
    }
}