// Написать рекурсивную функцию для разложения числа N на сумму слагаемых, 
// каждое из которых не должно превышать K

#include <iostream>
#include <vector>

void generatePartitions(int N, int K, std::vector<int>& currentPartition) {
    if (N == 0) {
        for (size_t i = 0; i < currentPartition.size(); ++i) {
            std::cout << currentPartition[i];
            if (i < currentPartition.size() - 1) {
                std::cout << " + ";
            }
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