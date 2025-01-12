// Дан class Tree с (Node *left, Node *Right, int amount). 
// Нужно подсчитать количество вершин дерева.

#include <iostream>

class Tree {
    public:
        int amount;
        Tree* left;
        Tree* right;

    Tree(int value) : amount(value), left(nullptr), right(nullptr) {} 
};

int count_Nodes(Tree* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + count_Nodes(root->left) + count_Nodes(root->right);
}

int main() {
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);

    int total_Nodes = count_Nodes(root);
    std::cout << total_Nodes;
}