#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>


class Graph {
private:
    std::vector<std::vector<int>> adjList;
    int vertexCount; 

public:
    Graph(int vertices);
    void addEdge(int u, int v);
    std::vector<std::vector<int>> bfs(int root);
};
