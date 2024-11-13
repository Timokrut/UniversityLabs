#include "header.h" 
#include <fstream>
#include <ostream>

void Graph::dfs(int u, int parent, int& time)
{
    visited[u] = true;
    disc[u] = low[u] = ++time;
    int children = 0;

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            children++;
            dfs(v, u, time);
            low[u] = std::min(low[u], low[v]);

        if (parent != -1 && low[v] >= disc[u])
            isArticulation[u] = true;

        if (parent == -1 && children > 1)
            isArticulation[u] = true;
        }
        else if (v != parent)
            low[u] = std::min(low[u], disc[v]);
    }
}

Graph::Graph(int verticies) : V(verticies), adj(verticies), visited(verticies, false), disc(verticies, -1), low(verticies, -1), isArticulation(verticies, false) {}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::findArticulationPoints()
{
    int time = 0;
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, -1, time);

    std::ofstream outputFile("articulation_points.txt");

    outputFile << "Articulation Points: ";
    for (int i = 0; i < V; i++)
        if (isArticulation[i])
            outputFile << i << " ";
    
    outputFile << std::endl;
    outputFile.close();
}
