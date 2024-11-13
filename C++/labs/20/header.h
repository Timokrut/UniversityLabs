#include <iostream>
#include <csignal>
#include <ostream>
#include <vector>
#include <fstream>
#include <sstream>

class Graph {
    private:
        std::vector<std::vector<int>>adjacentcyMatrix;
        int vertexCount;
        int startVertex;
        int dc;
        std::vector<int> path;
        std::vector<bool> visited;
        std::vector<std::vector<int>> cycles;

        void dfs(int currentVertex);

    public:
        Graph(const std::vector<std::vector<int>>& matrix);
        std::vector<std::vector<int>> findCycles(int startVertex, int dc);
};


