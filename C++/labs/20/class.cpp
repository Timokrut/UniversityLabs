#include "header.h"
void Graph::dfs(int currentVertex)
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

Graph::Graph(const std::vector<std::vector<int>>& matrix) : adjacentcyMatrix(matrix), vertexCount(matrix.size()), visited(matrix.size()) {}


std::vector<std::vector<int>> Graph::findCycles(int startVertex, int dc)
{
    this->startVertex = startVertex;
    this->dc = dc;
    path.clear();
    for (int i = 0; i < visited.size(); i++) visited[i] = false;
    cycles.clear();

    dfs(startVertex);
    return cycles;
}
