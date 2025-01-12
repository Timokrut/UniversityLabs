// Написать функцию, которая берет на вход std::vector<string> и возвращает строку, которая встречается в векторе чаще всего.
// Функция должна использовать std::map

#include <iostream>
#include <vector>
#include <string>
#include <map>

std::string func(std::vector<std::string> vec) {
    std::map<std::string, int> map;
    for (auto el : vec) { 
        map[el]++;
    }

    int max_quantity = 0;
    std::string max_str;

    for (auto pair : map) {
        if (pair.second >= max_quantity) {
            max_quantity = pair.second;
            max_str = pair.first;
        }
    }
    return max_str;
}


int main() {
    std::vector<std::string> vec = {"hello", "world", "hello"};
    std::string str = func(vec);
    std::cout << str << std::endl;
}