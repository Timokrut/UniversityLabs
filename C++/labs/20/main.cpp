// Ориентированный граф задан и хранится матрицей смежности.
// В файле задается вершина, с которой начинается обход и длина цикла dc. 
// Выписать все циклы, длина которых меньше dc.

#include "header.h"
#include <sstream>

int main()
{
    
    std::ifstream inputFile("matrix.txt");
    std::vector<std::vector<int>> graphMatrix;

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::vector<int> row;
        std::stringstream ss(line);
        int value;
        char comma;

        while (ss >> value)
        {
            row.push_back(value);
            ss >> comma;
        }

        graphMatrix.push_back(row);
    }

    int startVertex = 0;
    int dc = 4;

    Graph graph(graphMatrix);
    std::vector<std::vector<int>> cycles = graph.findCycles(startVertex, dc);

    std::ofstream outputFile("result.txt");

    for (const auto& cycle : cycles)
    {
        for (int vertex : cycle)
            outputFile << vertex << "->";
        outputFile << startVertex << std::endl;
    }

    std::cout << "Saved result to result.txt";
    return 0;
}    
