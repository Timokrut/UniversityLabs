// Написать функцию, которая берет на вход std::vector<int>, int before, int after и вставляет после каждого числа before число after.

#include <iostream>
#include <vector>

void func(std::vector<int>& vec, int before, int after) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == before) {
            vec.insert(vec.begin() + i + 1, after);
            i++;
        }
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3, 2, 4, 5, 2};
    int before = 2;
    int after = 0;

    func(vec, before, after);
    
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;        
}