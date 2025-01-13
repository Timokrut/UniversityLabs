// Алгоритмы простая. Написать функцию, которая рекурсивно генерирует все разложения числа N на слагаемых, 
// где каждое слагаемое не превышает K.

#include <iostream>
#include <vector>

void generatePartitions(int N, int K, std::vector<int>& currentPartition) {
    if (N == 0) {
        for (auto el : currentPartition) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = 1; i <= std::min(N, K); ++i) {
        currentPartition.push_back(i);
        generatePartitions(N - i, K, currentPartition);
        currentPartition.pop_back();
    }
}

int main() {
    int N, K;
    std::cout << "Введите число N: ";
    std::cin >> N;
    std::cout << "Введите ограничение K: ";
    std::cin >> K;

    std::vector<int> partition;
    std::cout << "Разложения числа " << N << " на слагаемые, не превышающие " << K << ":\n";
    generatePartitions(N, K, partition);

    return 0;
}