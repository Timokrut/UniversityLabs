#include "header.h"

Graph::Graph(int vertices) : vertexCount(vertices) {
    adjList.resize(vertices);
}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
}

std::vector<std::vector<int>> Graph::bfs(int root) 
{
    std::vector<bool> visited(vertexCount, false);  
    std::vector<std::vector<int>> paths(vertexCount);

    std::queue<int> q;
    visited[root] = true;
    q.push(root);
    paths[root].push_back(root);  

    while (!q.empty()) 
    {
        int vertex = q.front();
        q.pop();

        for (int neighbor : adjList[vertex]) 
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);

                paths[neighbor] = paths[vertex];
                paths[neighbor].push_back(neighbor);
            }
    }

    return paths;
}
