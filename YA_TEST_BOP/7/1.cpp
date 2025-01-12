// Написать шаблонную функцию, аргументы которой массивы str1, str2, result и их длины. 
// В result скопировать наибольший массив. Если не хватает длины result, нужно использовать throw и std::exception

#include <iostream>
#include <algorithm>

template <typename T> void func(T* str1, size_t size1, T* str2, size_t size2, T* result, size_t size3) {
    size_t max_size;
    T* max_array = nullptr;

    if (size1 > size2) {
        max_size = size1;
        max_array = str1;
    } else {
        max_size = size2;
        max_array = str2;
    }

    if (max_size > size3)
        throw std::exception();

    std::copy(max_array, max_array + max_size, result);
}

int main() {
    char str1[] = "Hello";
    char str2[] = "World!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    char result[10] = {"0"};

    try {
        func(str1, 5, str2, sizeof(str2) / sizeof(str2[0]), result, 10); // Успешный вызов
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: Not enough space in result" << std::endl;
    }

    return 0;
}
