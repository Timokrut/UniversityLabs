// Алгоритмы сложная. Дан лабиринт в виде двумерного массива: 0 - проход, 1 - стена, 2 - выход (всегда есть). 
// Написать рекурсивную функцию, которая получает на вход координаты старта и строит в лабиринте путь (заполняет цифрой 3) путь от старта до выхода.


#include <iostream>
#include <vector>

bool is_valid(int x, int y, std::vector<std::vector<int>>& maze) {
    return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && (maze[x][y] == 0 || maze[x][y] == 2);
}

bool find_path(std::vector<std::vector<int>>& maze, int x, int y) {
    if (maze[x][y] == 2) {
        return true;
    }

    // mark as path 
    maze[x][y] = 3;

    // up, down, left, right
    const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (const auto& [dx, dy] : directions) {
        int nx = x + dx;
        int ny = y + dy;

        if (is_valid(nx, ny, maze)) {
            if (find_path(maze, nx, ny)) {
                return true;
            }
        }
    }

    // no way out from current point
    maze[x][y] = 0;
    return false;
}

int main() {
    std::vector<std::vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 2},
        {0, 0, 0, 0, 0}
    };

    int start_x = 0;
    int start_y = 0;

    if (is_valid(start_x, start_y, maze)) {
        std::cout << "Incorrect position" << std::endl;
    }

    if (find_path(maze, start_x, start_y)) {
        std::cout << "Found a way out: " << std::endl;
        for (const auto& row : maze) {
            for (auto cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No way out" << std::endl;
    }

    return 0;
}