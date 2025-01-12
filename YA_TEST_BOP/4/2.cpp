// Написать функцию, которая берет на вход std::list<int> и удаляет из него все нечётные числа.


#include <iostream>
#include <list>

void func(std::list<int>& lst) {
    for (auto it = lst.begin(); it != lst.end();) {
        if (*it % 2 == 1)
            it = lst.erase(it);
        else
            it++;
    }
}

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    func(lst);

    for (auto el : lst)
        std::cout << el << " ";
    std::cout << std::endl;    
}