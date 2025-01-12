// Дан std::vector с string значениями. Нужно написать функцию которая найдет самую часто встречающуюся строчку. Нужно использовать std::map

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
    std::string max_string;

    for (auto pair : map) {
        if (pair.second >= max_quantity) {
            max_string = pair.first;
            max_quantity = pair.second;
        }    
    }
    return max_string;
}

int main() {
    std::vector<std::string> vec = {"hello", "world", "hello"};
    std::string str = func(vec);
    std::cout << str;
}