// Алгоритмы простая: рекурсивно сгенерировать все автомобильные номера, в которых N английских букв и М цифр.

#include <iostream>
#include <vector>
#include <string>

void gen_numbers(int N, int M, std::string current, std::vector<std::string>& results) {
    if (N == 0 && M == 0) {
        results.push_back(current);
        return;
    }

    if (N > 0) {
        for (char letter = 'A'; letter <= 'Z'; letter++) {
            gen_numbers(N - 1, M, current + letter, results);
        }
    }

    if (M > 0) {
        for (char digit = '0'; digit <= '9'; digit++) {
            gen_numbers(N, M - 1, current + digit, results);
        }
    }
}

int main() {
    int N = 2;
    int M = 2;
    std::string cur;
    std::vector<std::string> res;
    
    gen_numbers(N, M, cur, res);
    for (auto el : res) {
        std::cout << el << " ";
    }
}