// Алгоритмы простая: Давно дерево class Node {Node* left; Node* right; int value}; 
// Написать рекурсивную функцию для подсчета числа вершин

#include <iostream>

class Node {
    public:
        int value;
        Node* left;
        Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

int count_nodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int main() {
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int total_Nodes = count_nodes(root);
    std::cout << total_Nodes;
}