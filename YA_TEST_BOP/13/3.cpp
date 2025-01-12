// Алгоритмы простая:
// Написать программу, которая выводит все идентификаторы вершин дерева, у которых ровно 3 сына. 
// Вершина дерева хранитсмя как class Node {int val; vector<Node> childs};

#include <iostream>
#include <vector>

class Node {
    public: 
        int value;
        std::vector<Node*> childs;
    
    Node(int val) : value(val) {}
};

void print_values(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->childs.size() == 3) {
        std::cout << root->value << std::endl;
    }

    for (Node* child : root->childs) {
        print_values(child);
    }
}

int main() {
    //        1
    //      / | \
    //     2  3  4
    //        |
    //        5

    Node* root = new Node(1);
    root->childs.push_back(new Node(2));
    root->childs.push_back(new Node(3));
    root->childs.push_back(new Node(4));
    root->childs[1]->childs.push_back(new Node(5)); 

    print_values(root);

    for (Node* child : root->childs) {
        for (Node* grandchild : child->childs) {
            delete grandchild;
        }
        delete child;
    }
    delete root;

    return 0;
}