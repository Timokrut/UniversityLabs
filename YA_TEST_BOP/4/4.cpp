// Алгоритмы сложная. Написать программу, которая для каждого ребра графа выписывает , является ли оно ребром древа или ребром графа (после dfs)

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

enum EdgeType {
    TREE_EDGE,
    BACK_EDGE
};

void dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited, vector<tuple<int, int, EdgeType>>& edges) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            // Древесное ребро
            edges.emplace_back(node, neighbor, TREE_EDGE);
            dfs(neighbor, node, adj, visited, edges);
        } else if (neighbor != parent) {
            // Обратное ребро
            edges.emplace_back(node, neighbor, BACK_EDGE);
        }
    }
}

int main() {
    int n, m;
    cout << "Введите количество вершин (n): ";
    cin >> n;
    cout << "Введите количество рёбер (m): ";
    cin >> m;

    vector<vector<int>> adj(n);
    cout << "Введите рёбра графа (две вершины на каждое ребро):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Для неориентированного графа
    }

    vector<bool> visited(n, false);
    vector<tuple<int, int, EdgeType>> edges;

    // Запуск DFS для каждой компоненты связности
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, -1, adj, visited, edges);
        }
    }

    cout << "Рёбра графа и их типы:\n";
    for (const auto& [u, v, type] : edges) {
        cout << u << " - " << v << " : " 
             << (type == TREE_EDGE ? "Tree Edge" : "Back Edge") << "\n";
    }

    return 0;
}
