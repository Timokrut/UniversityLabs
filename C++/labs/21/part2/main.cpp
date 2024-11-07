// Реализовать алгоритм поиска точек сочленения для графа, представленного списком ребер
#include "header.h"

int main()
{
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    graph.findArticulationPoints();

    return 0;
}
