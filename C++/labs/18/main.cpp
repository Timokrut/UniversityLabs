#include "header.h"


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
