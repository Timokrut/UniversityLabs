// Алгоритмы простая. Написать программу, которые выводит все идентификаторы вершин дерева, 
// у которых ровно три сына. Вершина дерева хранится как class Node { int val; vector<Node> childs;).


#include <iostream>
#include <vector>

class Node {
    public:
        int value;
        std::vector<Node*> childs;

    Node(int val) : value(val) {}
};

void print_Nodes(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->childs.size() == 3) {
        std::cout << root->value << std::endl;
    }

    for (auto child : root->childs) {
        print_Nodes(child);
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
    root->childs[1]->childs.push_back(new Node(6)); 
    root->childs[1]->childs.push_back(new Node(7)); 

    print_Nodes(root);

    for (Node* child : root->childs) {
        for (Node* grandchild : child->childs) {
            delete grandchild;
        }
        delete child;
    }
    delete root;

    return 0;
}