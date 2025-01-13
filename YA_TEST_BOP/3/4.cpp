// Алгоритмы сложная. Сгенерировать все варианты полных (всегда два потомка у вершины) двоичных деревьев из n вершин.


#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Структура для узла дерева
struct TreeNode {
    int value; // Значение вершины (можно не использовать, но удобно для отладки)
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функция для генерации всех полных двоичных деревьев
vector<shared_ptr<TreeNode>> generate_full_binary_trees(int n) {
    // Базовый случай: если n нечётное, возвращаем пустой список
    if (n % 2 == 0) return {};

    // Базовый случай: если n == 1, возвращаем дерево с единственным узлом
    if (n == 1) return {make_shared<TreeNode>(0)};

    vector<shared_ptr<TreeNode>> result;

    // Разбиваем n - 1 оставшиеся вершины на два поддерева
    for (int left_count = 1; left_count < n; left_count += 2) {
        int right_count = n - 1 - left_count;

        // Рекурсивно генерируем все варианты для левого и правого поддеревьев
        vector<shared_ptr<TreeNode>> left_trees = generate_full_binary_trees(left_count);
        vector<shared_ptr<TreeNode>> right_trees = generate_full_binary_trees(right_count);

        // Комбинируем каждое левое поддерево с каждым правым
        for (auto& left : left_trees) {
            for (auto& right : right_trees) {
                auto root = make_shared<TreeNode>(0);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    return result;
}

// Вспомогательная функция для вывода дерева (обход в глубину)
void print_tree(shared_ptr<TreeNode> root, int depth = 0) {
    if (!root) return;
    print_tree(root->right, depth + 1);
    cout << string(depth * 4, ' ') << "o\n";
    print_tree(root->left, depth + 1);
}

int main() {
    int n;
    cout << "Введите число вершин (n): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Невозможно сгенерировать полное двоичное дерево с чётным числом вершин.\n";
        return 1;
    }

    vector<shared_ptr<TreeNode>> trees = generate_full_binary_trees(n);

    cout << "Количество деревьев: " << trees.size() << "\n";
    for (size_t i = 0; i < trees.size(); ++i) {
        cout << "Дерево " << i + 1 << ":\n";
        print_tree(trees[i]);
        cout << "----\n";
    }

    return 0;
}
