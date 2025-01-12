// Написать функцию, которая берет на вход std:: list<int> и возвращает число, которое встречается в векторе чаще всего. 
// Функция должна использовать std::map.


#include <iostream>
#include <list>
#include <map>

void func(std::list<int> list) {
    std::map<int, int> map;
    for (auto el : list) {
        map[el]++;
    }

    int max_quantity = 0;
    int max_number = 0;

    for (auto pair : map) {
        if (pair.second >= max_quantity) {
            max_number = pair.first;
            max_quantity = pair.second;
        }
    }
    std::cout << "max number: " << max_number << " appeared " << max_quantity << " times" << std::endl; 
}

int main() {
    std::list<int> list = {1, 2, 3, 4, 2, 2, 1, 3, 4, 5, 6, 1, 1, 2, 2, 2};
    func(list);
}