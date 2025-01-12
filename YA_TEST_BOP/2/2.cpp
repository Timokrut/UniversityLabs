// Написать функцию, которая берет на вход std::vector<string> и возвращает строку, которая встречается в векторе чаще всего 
// Функция должна использовать std::map.


#include <iostream>
#include <vector>
#include <string>
#include <map>

std::string func(std::vector<std::string>& vec) {
    std::map<std::string, int> map;

    for (const auto& str : vec) {
        map[str]++;
    }

    std::string max_freq_str;
    int max_freq = 0;
    for (const auto& pair : map) {
        if (pair.second > max_freq)
            max_freq = pair.second;
            max_freq_str = pair.first;
    }

    return max_freq_str;
}

int main() {
    std::vector<std::string> vec;
    vec.push_back("hello");
    vec.push_back("world");
    vec.push_back("world");

    std::string str = func(vec);
    std::cout << str;
}