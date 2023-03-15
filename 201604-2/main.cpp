// ccf-csp 201604-2

#include <iostream>

using namespace std;

int tetris[15][10]{0};
int next_block[4][4]{0};

int main() {
    ios::sync_with_stdio(false);
    // 输入
    for (int i{}; i < 15; ++i) {
        for (int j{}; j < 10; ++j) {
            cin >> tetris[i][j];
        }
    }
    for (int i{}; i < 4; ++i) {
        for (int j{}; j < 4; ++j) {
            cin >> next_block[i][j];
        }
    }
    int pos{};
    cin >> pos;
    // 输出
    for (int i{}; i < 15; ++i) {
        for (int j{}; j < 10; ++j) {
            cout << tetris[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
