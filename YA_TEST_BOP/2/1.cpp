// Написать шаблонную функцию, которая берет на вход два массива src1 и src2 шаблонного типа и их длину (известно, что массивы имеют одинаковую длину). 
// Функция выводит на экран результаты поэлементного деления элементов первого массива на второй. Если делитель равен 0, 
// то функция бросает исключение типа std::exception.

#include <iostream>

template <typename T> void func(T* src1, size_t size1, T* src2, size_t size2) {
    for (size_t i = 0; i < size1; i++)
    {
        if (src2[i] == 0)
            throw std::exception();

        std::cout << src1[i] / src2[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    try {
        size_t size1 = 5;
        size_t size2 = 5;
        int array1[size1] = {1, 2, 3, 4, 5};
        int array2[size2] = {5, 4, 0, 2, 1};

        func(array1, size1, array2, size2);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}