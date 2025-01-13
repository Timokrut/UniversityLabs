// Алгоритмы сложная. Сгенерировать все возможные графы, в которых у каждой вершины k соседей. 
// Задается число вершин в графе n и число k.


#include <iostream>
#include <vector>
#include <algorithm>

bool is_k_regular(std::vector<std::vector<int>>& graph, int k) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            degree += graph[i][j];
        }
        if (degree != k) return false;
    }
    return true;
}

void generate_graphs(int n, int k, std::vector<std::vector<int>>& graph, int row, int col, std::vector<std::vector<std::vector<int>>>& result) {
    if (row == n) {
        if (is_k_regular(graph, k)) {
            result.push_back(graph);
        }
        return;
    }

    if (col == n) {
        generate_graphs(n, k, graph, row + 1, row + 2, result);
        return;
    }

    if (col <= row) {
        generate_graphs(n, k , graph, row, col + 1, result);
    }

    graph[row][col] = graph[col][row] = 1;
    generate_graphs(n, k, graph, row, col + 1, result);

    graph[row][col] = graph[col][row] = 0;
    generate_graphs(n, k, graph, row, col + 1, result);
}


int main() {
    int n = 3;
    int k = 2;

    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
    std::vector<std::vector<std::vector<int>>> result;

    generate_graphs(n, k, graph, 0, 1, result);

    std::cout << "Сгенерировано графов: " << result.size() << "\n";
    for (const auto& g : result) {
        for (const auto& row : g) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
        std::cout << "----\n";
    }

    return 0;
}