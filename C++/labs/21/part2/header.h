#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Graph {
    private:
        int V;
        std::vector<std::vector<int>> adj;
        std::vector<bool> visited;
        std::vector<int> disc;
        std::vector<int> low;
        std::vector<bool> isArticulation;
        void dfs(int u, int parent, int& time); 

    public:
        Graph(int verticies);
        void addEdge(int u, int v);
        void findArticulationPoints();
};

