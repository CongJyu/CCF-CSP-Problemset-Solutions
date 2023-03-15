// ccf-csp 201312-5

/*
 * 使用深度优先搜索
 * 需要两次 DFS，从 S 点开始，找出其他可以到达的点
 * 如果从 S 不能到达 T，则输出 "I'm stuck!"
 * 否则从 S 可以到达的点开始，逐个搜索其可到达的点，统计不可以到达 T 点的点的数量
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int N{50};
const int DIRECT_SIZE{4};

struct Direction {
    int dr;
    int dc;
};

Direction direct[DIRECT_SIZE]{
        {-1, 0},
        {1,  0},
        {0,  -1},
        {0,  1}
};

char grid[N][N + 1];
int visited[N][N], visited_2[N][N];

int r, c;

// 判断坐标是否可以移动到
inline bool is_legal(int row, int col) {
    if (0 <= row and row < r and 0 <= col and col < c and !visited[row][col] and grid[row][col] != '#') {
        return true;
    } else {
        return false;
    }
}

// dfs
void dfs(int row, int col) {
    int next_r, next_c;
    visited[row][col] = 1;

    if (grid[row][col] == '+' or grid[row][col] == 'S' or grid[row][col] == 'T') {
        // 格子里是 '+' 或者是 起点 或者是 终点
        for (int i{}; i < DIRECT_SIZE; ++i) {
            next_r = row + direct[i].dr;
            next_c = col + direct[i].dc;
            if (is_legal(next_r, next_c)) {
                dfs(next_r, next_c);
            }
        }
    } else if (grid[row][col] == '-') {
        // 只能往左右走
        for (int i{2}; i < DIRECT_SIZE; ++i) {
            next_r = row + direct[i].dr;
            next_c = col + direct[i].dc;
            if (is_legal(next_r, next_c)) {
                dfs(next_r, next_c);
            }
        }
    } else if (grid[row][col] == '|') {
        // 只能往上下走
        for (int i{}; i < 2; ++i) {
            next_r = row + direct[i].dr;
            next_c = col + direct[i].dc;
            if (is_legal(next_r, next_c)) {
                dfs(next_r, next_c);
            }
        }
    } else if (grid[row][col] == '.') {
        // 只能向下走
        next_r = row + direct[1].dr;
        next_c = col + direct[1].dc;
        if (is_legal(next_r, next_c)) {
            dfs(next_r, next_c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int sr{}, sc{}, tr{}, tc{};
    // 输入
    cin >> r >> c;
    for (int i{}; i < r; ++i) {
        cin >> grid[i];
    }
    for (int i{}; i < r; ++i) {
        for (int j{}; j < c; ++j) {
            if (grid[i][j] == 'S') {
                // 找到起点
                sr = i;
                sc = j;
            } else if (grid[i][j] == 'T') {
                // 找到终点
                tr = i;
                tc = j;
            }
        }
    }
    // bfs 标记从 S 可以到达的点
    memset(visited, 0, sizeof(visited));
    dfs(sr, sc);
    memcpy(visited_2, visited, sizeof(visited));
    if (visited_2[tr][tc]) {
        int count{};
        // 统计 S 点可以到达 但是不能到达 T 点的点的数量
        for (int i{}; i < r; ++i) {
            for (int j{}; j < c; ++j) {
                if (visited_2[i][j]) {
                    // bfs 标记从 <i, j> 可以到达的点，如果不能到达 T 点就计数
                    memset(visited, 0, sizeof(visited));
                    dfs(i, j);
                    if (!visited[tr][tc]) {
                        count++;
                    }
                }
            }
        }
        // 输出 count
        cout << count << endl;
    } else {
        // 从 S 点不能到达 T 点
        cout << "I'm stuck!" << endl;
    }
    return 0;
}
