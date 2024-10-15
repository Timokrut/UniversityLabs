#include <iostream>
#include <map>
#include <ostream>
#include <stdexcept>
#include <string>

class Node {
public:
    std::string name;
    std::map<std::string, Node> children;

    Node() = default;
    Node(const std::string& str) : name(str) {}

    friend std::ostream& operator<<(std::ostream& os, const Node& node) 
    {
        return node.print(os, 0);
    }

private:
    std::ostream& print(std::ostream& os, int indent) const 
    {
        for (int i = 0; i < indent; i++) 
        {
            os << (i == indent - 1 ? "|-- " : "   ");
        }

        os << name << "\n";

        for (const auto& childPair : children) {
            const Node& childNode = childPair.second;
            childNode.print(os, indent + 1);
        }
        return os;
    }
};

class Tree {
private:
    Node* root;

public:
    Tree() : root(nullptr) {}

    void addRoot(const std::string& rootName) 
    {
        root = new Node(rootName);
    }

    void addNode(const std::string& parent, const std::string nodeName) 
    {
        if (root == nullptr)
            throw std::runtime_error("No roots found!");

        Node* parentNode = findNode(*root, parent);
        if (parentNode)
            parentNode->children[nodeName] = Node(nodeName);
        else
            std::cout << "Error! Node " << parent << " is not found" << std::endl;
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

        for (auto& childPair : currentNode.children) {
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
    tree.addNode("root", "child3");
    tree.addNode("child1", "child1_1");
    tree.addNode("child1", "child1_2");
    tree.addNode("child2", "child2_1");
    
    std::cout << tree;

    return 0;
}
