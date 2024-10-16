#include "header.h"


Node::Node(const std::string& str) : name(str) {}

std::ostream& operator<<(std::ostream& os, const Node& node) 
{
    return node.print(os, 0);
}

std::ostream& Node::print(std::ostream& os, int indent) const 
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

Tree::Tree() : root(nullptr) {}

void Tree::addRoot(const std::string& rootName) 
{
    root = new Node(rootName);
}

void Tree::addNode(const std::string& parent, const std::string nodeName) 
{
    if (root == nullptr)
        throw std::runtime_error("No roots found!");

    Node* parentNode = findNode(*root, parent);
    if (parentNode)
        parentNode->children[nodeName] = Node(nodeName);
    else
        std::cout << "Error! Node " << parent << " is not found" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Tree& tree) 
{
    if (tree.root)
        os << *tree.root;
    else
        os << "Tree is empty";
    return os;
}

Node* Tree::findNode(Node& currentNode, const std::string& nodeName) 
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
