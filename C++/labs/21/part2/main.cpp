// Реализовать алгоритм поиска точек сочленения для графа, представленного списком ребер
#include "header.h"

int main()
{
    Graph graph(5);

    std::ifstream inputFile("edges.txt");
    std::string line;

    while (std::getline(inputFile, line))
    {
        int value;
        char comma;
        std::vector<int> vector;

        std::stringstream ss(line);

        while (ss >> value)
        {
            vector.push_back(value);
            ss >> comma;
        }

        graph.addEdge(vector[0], vector[1]);
    }
    graph.findArticulationPoints();
    std::cout << "Saved articulation points to articulation_points.txt" << std::endl;

    return 0;
}
