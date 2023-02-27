// ccf csp 202212-3

#include <iostream>

using namespace std;

int q_mat[1001][1001];
// int m_mat[8][8] = {0};
int scanned_data[10001];

struct Matrix {
    int order;
    int data;
} m_mat[8][8];

int main() {
    ios::sync_with_stdio(false);
    for (int i{}; i < 8; ++i) {
        for (int j{}; j < 8; ++j) {
            cin >> q_mat[i][j];
        }
    }
    int n{};  // 數據個數
    cin >> n;
    int T{};  // 任務
    cin >> T;
    for (int i{}; i < n; ++i) {
        cin >> scanned_data[i];
    }
    
    return 0;
}
