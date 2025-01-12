// Написать функцию, которая берет на вход std::list<int> и удаляет из него все нечётные числа.

#include <iostream>
#include <list>


void func(std::list<int>& list) {
    for (auto it = list.begin(); it != list.end();it++) {
        if (*it % 2 == 1) 
            it = list.erase(it);
    }
}

int main() {
    std::list<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    func(list);
    for (auto it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
}