// Ориентированный граф задан и хранится матрицей смежности.
// В файле задается вершина, с которой начинается обход и длина цикла dc. 
// Выписать все циклы, длина которых меньше dc.

#include "header.h"

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
