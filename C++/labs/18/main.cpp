#include <iostream>
#include <map>
#include <ostream>
#include <stdexcept>
#include <string>

// Реализовать дерево, где у узла может быть несколько детей (т.е. может быть недвоичное дерево). Использовать map<std::string, Node>, т.е. каждый узел в дереве характеризуется строкой. Node хранит список детей.
// addRoot(const std::string& rootName)
// addNode(const std::string& parent,  const std::string& nodeName)
// operator<< для вывода на экран

class Node{
    public:
        std::string name;
        std::map<std::string, Node> children;
        
        Node() = default;
        Node(const std::string& str): name(str) {}

        friend std::ostream& operator<<(std::ostream& os, const Node& node)
        {
            os << node.name << "\n";
            for (const auto& childPair : node.children)
            {
                const std::string childName = childPair.first;
                const Node& childNode = childPair.second;
                os << "--" << childNode;
            }
            return os;
        }
};

class Tree{
    private:
        Node* root;
    
    public:
        Tree(): root(nullptr) {}

        void addRoot(const std::string& rootName) 
        {
            root = new Node(rootName);
        }

        void addNode(const std::string& parent, const std::string nodeName) 
        {
            if (root == nullptr)
                std::runtime_error("No roots found!");

            Node* parentNode = findNode(*root, parent);
            if (parentNode)
                parentNode->children[nodeName] = Node(nodeName);
            else
                std::cout << "Error! Node "<< parent << "is not found" << std::endl;
        }

        friend std::ostream& operator<<(std::ostream& os, const Tree& tree)
        {
            if (tree.root)
                os << *tree.root;
            else
                os << "Tree is empty";
            return os;
        }

    private:
        Node* findNode(Node& currentNode, const std::string& nodeName) 
        {
            if (currentNode.name == nodeName)
                return &currentNode;

            for (auto& childPair : currentNode.children)
            {
                Node& childNode = childPair.second;
                Node* foundNode = findNode(childNode, nodeName);
                if (foundNode)
                    return foundNode;
            }
            return nullptr;
        }
        

};

int main()
{
    Tree tree;
    tree.addRoot("root");
    tree.addNode("root", "child1");
    tree.addNode("root", "child2");
    tree.addNode("child1", "child1_1");
    tree.addNode("child1", "child1_2");
    
    std::cout << tree;

    return 0;
}
