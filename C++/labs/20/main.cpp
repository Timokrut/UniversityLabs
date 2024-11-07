// Ориентированный граф задан и хранится матрицей смежности.
// В файле задается вершина, с которой начинается обход и длина цикла dc. 
// Выписать все циклы, длина которых меньше dc.

#include <iostream>
#include <csignal>
#include <ostream>
#include <vector>

class Graph {
    private:
        std::vector<std::vector<int>>adjacentcyMatrix;
        int vertexCount;

        int startVertex;
        int dc;
        std::vector<int> path;
        std::vector<bool> visited;
        std::vector<std::vector<int>> cycles;

        void dfs(int currentVertex)
        {
            path.push_back(currentVertex);
            visited[currentVertex] = true;

            for (int neighbor = 0; neighbor < vertexCount; neighbor++)
            {
                if (adjacentcyMatrix[currentVertex][neighbor] != 0) { 
                    if (neighbor == startVertex && path.size() < dc)
                        cycles.push_back(path);
                    
                    else if (!visited[neighbor] && path.size() + 1 < dc)
                    dfs(neighbor);
                }
            }

            path.pop_back();
            visited[currentVertex] = false;
        }

    public:
        Graph(const std::vector<std::vector<int>>& matrix) : adjacentcyMatrix(matrix), vertexCount(matrix.size()), visited(matrix.size()) {}


        std::vector<std::vector<int>> findCycles(int startVertex, int dc)
        {
            this->startVertex = startVertex;
            this->dc = dc;
            path.clear();
            for (int i = 0; i < visited.size(); i++) visited[i] = false;
            cycles.clear();

            dfs(startVertex);
            return cycles;
        }
};



int main()
{
    std::vector<std::vector<int>> graphMatrix = {
        {0, 1, 0, 0},
        {0, 0, 1, 0}, 
        {1, 0, 0, 1},
        {0, 0 , 0, 0}
    };
    int startVertex = 0;
    int dc = 4;

    Graph graph(graphMatrix);
    std::vector<std::vector<int>> cycles = graph.findCycles(startVertex, dc);

    for (const auto& cycle : cycles)
    {
        for (int vertex : cycle)
            std::cout << vertex << "->";
        std::cout << startVertex << std::endl;
    }

    return 0;
}    
