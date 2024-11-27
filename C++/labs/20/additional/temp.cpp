#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>

class Graph {
private:
    std::vector<std::vector<int>> adjList;  // Список смежности
    int vertexCount;  // Количество вершин

public:
    Graph(int vertices) : vertexCount(vertices) {
        adjList.resize(vertices);
    }

    // Добавление ребра между вершинами
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // Алгоритм BFS для поиска путей
    std::vector<std::vector<int>> findPathsFromRoot(int root) {
        std::vector<bool> visited(vertexCount, false);  // Массив посещенных вершин
        std::vector<std::vector<int>> paths(vertexCount);  // Массив путей

        // Очередь для BFS: храним пары (вершина, путь до этой вершины)
        std::queue<int> q;
        visited[root] = true;
        q.push(root);
        paths[root].push_back(root);  // Путь от корня до корня

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            // Проходим по всем соседям
            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);

                    // Сохраняем путь до соседа
                    paths[neighbor] = paths[vertex];  // Копируем путь до текущей вершины
                    paths[neighbor].push_back(neighbor);  // Добавляем соседа в путь
                }
            }
        }

        return paths;
    }
};

int main() {
    std::ifstream inputFile("adjacency_list.txt");
    std::string line;
    int root;

    // Чтение корня
    std::getline(inputFile, line);
    std::stringstream(line) >> root;

    // Чтение матрицы смежности и создание графа
    std::vector<std::vector<int>> adjMatrix;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::vector<int> row;
        int value;
        while (ss >> value) {
            row.push_back(value);
        }
        adjMatrix.push_back(row);
    }

    // Создание графа
    int vertexCount = adjMatrix.size();
    Graph graph(vertexCount);

    // Заполнение графа на основе матрицы смежности
    for (int i = 0; i < vertexCount; ++i) {
        for (int j = 0; j < vertexCount; ++j) {
            if (adjMatrix[i][j] == 1) {
                graph.addEdge(i, j);  // Добавляем ребро между вершинами i и j
            }
        }
    }

    // Получаем пути от корня
    std::vector<std::vector<int>> paths = graph.findPathsFromRoot(root);

    // Запись путей в файл
    std::ofstream outputFile("result.txt");
    for (int i = 0; i < vertexCount; ++i) {
        if (!paths[i].empty()) {
            for (size_t j = 0; j < paths[i].size(); ++j) {
                outputFile << paths[i][j];
                if (j != paths[i].size() - 1) {  // Если это не последняя вершина в пути
                    outputFile << "->";
                }
            }
            outputFile << "\n";
        }
    }



    std::cout << "Paths saved to result.txt" << std::endl;

    return 0;
}

