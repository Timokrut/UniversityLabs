// Алгоритмы простая. Дано дерево class Node { Node *left; Node *right; int value );. 
// Написать программу подсчета числа листьев в дереве.
// (Листья - узел без детей)
#include <iostream>

class Node {
    public: 
        int value;
        Node* left;
        Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}    
};

int count_leaves(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return count_leaves(root->left) + count_leaves(root->right);
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

    int total_Nodes = count_leaves(root);
    std::cout << total_Nodes;
}