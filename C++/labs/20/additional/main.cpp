// Ориентированный граф задан и хранится списком смежности. В файле задается вершина (корень), 
// с которой начинается обход. Выписать пути до каждой вершины от корня, используя алгоритм bfs.

#include "header.h"


int main() {
    std::ifstream inputFile("adjacency_list.txt");
    std::string line;
    int root;

    std::getline(inputFile, line);
    std::stringstream(line) >> root;
    
    int vertexCount = 0; 
    std::vector<std::vector<int>> adjList;
    while (std::getline(inputFile, line)) 
    {
        std::stringstream ss(line);
        std::vector<int> neighbours;
        int neighbour;
        while (ss >> neighbour)
            neighbours.push_back(neighbour);
        
        adjList.push_back(neighbours);
        vertexCount++;
    }

    Graph graph(vertexCount);

    for (int i = 0; i < vertexCount; i++) 
        for (int neighbour : adjList[i]) 
            graph.addEdge(i, neighbour);

    std::vector<std::vector<int>> paths = graph.bfs(root);

    std::ofstream outputFile("result.txt");
    for (int i = 0; i < vertexCount; ++i) 
        if (!paths[i].empty()) 
        {
            for (size_t j = 0; j < paths[i].size(); j++) 
            {
                outputFile << paths[i][j];
                if (j != paths[i].size() - 1) 
                    outputFile << "->";
            }
            outputFile << "\n";
        }
    

    std::cout << "Paths saved to result.txt" << std::endl;

    return 0;
}
