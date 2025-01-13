// Алгоритмы простая. Дана сумма S и набор чисел в виде массива. 
// Расставить между числами + и -, чтобы получилась сумма S.

#include<iostream>
#include<vector>

bool find_expression(int index, std::vector<int> numbers, int currentSum, int targetSum, std::vector<char> operators) {
    if (index == numbers.size()) {
        return currentSum == targetSum;
    }

    operators[index] = '+';
    if (find_expression(index + 1, numbers, currentSum + numbers[index], targetSum, operators)) {
        return true;
    }

    operators[index] = '-';
    if (find_expression(index + 1, numbers, currentSum - numbers[index], targetSum, operators)) {
        return true;
    }    

    return false;
}
void printExpression(const std::vector<int>& numbers, const std::vector<char>& operators) {
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i > 0) {
            std::cout << " " << operators[i] << " ";
        }
        std::cout << numbers[i];
    }
    std::cout << std::endl;
}

int main() {
    int S;
    std::cout << "Введите целевую сумму S: ";
    std::cin >> S;

    int n;
    std::cout << "Введите количество чисел в массиве: ";
    std::cin >> n;

    std::vector<int> numbers(n);
    std::cout << "Введите числа массива: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::vector<char> operators(n, '+');

    if (find_expression(1, numbers, numbers[0], S, operators)) {
        std::cout << "Найдено выражение:\n";
        printExpression(numbers, operators);
    } else {
        std::cout << "Нет решений для заданной суммы.\n";
    }

    return 0;
}
