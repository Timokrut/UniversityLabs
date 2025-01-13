#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>


// Number 1

template <typename T> void func(T* src1, size_t size1, T* src2, size_t size2) {
    if (size1 != size2) {
        throw std::exception();
    }

    for (size_t i = 0; i < size1; i++) {
        src2[i] = std::max(src1[i], src2[i]);
    }
}

// Number 2

int func(std::vector<int> vec) {
    std::set<int> set;

    for (size_t i = 0; i < vec.size(); i++) {
        set.insert(vec[i]);
    }
    return set.size();
}

// Number 3

void gen_number(int N, int K, std::string current, std::vector<std::string> result) {
    if (N == 0 && K == 0) {
        std::cout << current << std::endl;
        result.push_back(current);
        return;
    }

    if (N > 0) {
        for (char letter = 'A'; letter <= 'Z'; letter++) {
            current += letter;
            gen_number(N - 1, K, current, result);
        }
    }

    if (K > 0) {
        for (char digit = '0'; digit <= '9'; digit++) {
            current += digit;
            gen_number(N, K - 1, current, result);
        }
    }
}

// Number 4