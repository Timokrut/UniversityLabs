// Ориентированный граф задан и хранится матрицей смежности.
// В файле задается вершина, с которой начинается обход и длина цикла dc. 
// Выписать все циклы, длина которых меньше dc.

#include "header.h"
#include <sstream>
#include <string>

int main()
{
    
    std::ifstream inputFile("matrix.txt");
    std::vector<std::vector<int>> graphMatrix;
    std::string line;
    std::vector<int> parameters;
    
    if (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        int value1;
        int value2;
        char comma;
        
        ss >> value1;
        ss >> comma;
        ss >> value2;


        parameters.push_back(value1);
        parameters.push_back(value2);
    }
    
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

    int startVertex = parameters[0];
    int dc = parameters[1];

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
