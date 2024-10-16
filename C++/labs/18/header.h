#pragma once

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
    Node(const std::string& str);

    friend std::ostream& operator<<(std::ostream& os, const Node& node);

private:
    std::ostream& print(std::ostream& os, int indent) const; 
};

class Tree {
private:
    Node* root;

public:
    Tree();

    void addRoot(const std::string& rootName); 

    void addNode(const std::string& parent, const std::string nodeName); 

    friend std::ostream& operator<<(std::ostream& os, const Tree& tree); 

private:
    Node* findNode(Node& currentNode, const std::string& nodeName); 
};
