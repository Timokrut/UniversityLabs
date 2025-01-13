// Алгоритмы сложная. Написать нерекурсивную программу, печатающую все вершины двоичного дерева. Воспользоваться самодельным стеком (реализовывать не нужно).

#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};



class Stack {
    public:
        void push(TreeNode* node) {}
        bool is_empty() {};
        TreeNode* pop() {};
};


void printTree(TreeNode* root) {
    if (root == nullptr) {
        return; // Tree is empty
    }

    Stack stack;
    stack.push(root);

    while (!stack.is_empty()) {
        TreeNode* current = stack.pop();
        std::cout << current->value << " ";

        if (current->right) {
            stack.push(current->right);
        }

        if (current->left) {
            stack.push(current->left);
        }
    }
    std::cout << std::endl;
}

