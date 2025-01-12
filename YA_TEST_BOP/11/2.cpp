// Дан std::list, нужно найти самое часто появляющееся число с помощью std::map

#include <iostream>
#include <map>
#include <list>

int func(std::list<int> list) {
    std::map<int, int> map;
    for (auto el : list) {
        map[el]++;
    }    

    int max_int = 0;
    int max_freq = 0;

    for (auto pair : map) {
        if (pair.second >= max_freq) {
            max_freq = pair.second;
            max_int = pair.first;
        }
    }
    return max_int;
}


int main() {
    std::list<int> list = {1, 2, 3, 4, 5, 1, 2, 3, 4, 1, 2,3, 1, 2, 1};
    int num = func(list);
    std::cout << num << std::endl;
}