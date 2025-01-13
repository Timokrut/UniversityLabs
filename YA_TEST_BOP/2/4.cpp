// Алгоритмы сложная. Написать программу, которая проверяет является ли граф деревом.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Функция для проверки наличия циклов с использованием DFS
bool has_cycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (has_cycle(neighbor, node, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            // Если сосед уже посещён и не является родительской вершиной, значит есть цикл
            return true;
        }
    }

    return false;
}

// Функция для проверки связности графа
bool is_connected(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    // Запускаем BFS/DFS с любой вершины
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // Проверяем, что все вершины посещены
    for (bool v : visited) {
        if (!v) return false;
    }

    return true;
}

// Основная функция для проверки, является ли граф деревом
bool is_tree(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);

    // Проверка на наличие циклов
    if (has_cycle(0, -1, adj, visited)) {
        return false;
    }

    // Проверка связности
    if (!is_connected(adj, n)) {
        return false;
    }

    return true;
}

int main() {
    int n, m;
    cout << "Введите число вершин (n): ";
    cin >> n;
    cout << "Введите число рёбер (m): ";
    cin >> m;

    // Если количество рёбер не равно n-1, граф не может быть деревом
    if (m != n - 1) {
        cout << "Граф не является деревом (некорректное количество рёбер).\n";
        return 0;
    }

    vector<vector<int>> adj(n);
    cout << "Введите рёбра графа (две вершины на каждое ребро):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (is_tree(adj, n)) {
        cout << "Граф является деревом.\n";
    } else {
        cout << "Граф не является деревом.\n";
    }

    return 0;
}
