// Написать функцию, которая берет на вход std::vector<int> и возвращает количество различных чисел. 
// Функция должна использовать std::set.
#include <iostream>
#include <vector>
#include <set>

int func(std::vector<int> vec) {
    std::set<int> set;
    for (size_t i = 0; i < vec.size(); i++)
        set.insert(vec[i]);

    return set.size(); 
}

int main() {
    std::vector vec {1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 7};
    int var = func(vec);
    std::cout << var << std::endl;
}