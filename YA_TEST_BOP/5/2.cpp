// Написать функцию, которая берет на вход std::list<string> и возвращает количество различных строк. Функция должна использовать std::set.

#include <iostream>
#include <list>
#include <string>
#include <set>

int func(std::list<std::string> list) {
    std::set<std::string> set;
    for (auto el : list) {
        set.insert(el);
    }
    return set.size();
}


int main() {
    std::list<std::string> list {"hello", "world", "world", "bob", "hole"};
    list.push_back("amogus");

    int ret = func(list);
    std::cout << ret << std::endl;
}
