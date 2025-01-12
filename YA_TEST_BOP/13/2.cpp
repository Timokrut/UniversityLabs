// Написать функцию, которая берет на вход std::list<string> и возвращает количество различных строк. Функция должна использовать std::set

#include <list>
#include <string>
#include <set>
#include <iostream>


int func(std::list<std::string> list) {
    std::set<std::string> set;
    for (auto el : list) {
        set.insert(el);
    }
    return set.size();
}

int main() {
    std::list<std::string> list = {"hello", "world", "hello", "world", "bob", "wow", "hello"};
    int num = func(list);
    std::cout << num << std::endl;
}