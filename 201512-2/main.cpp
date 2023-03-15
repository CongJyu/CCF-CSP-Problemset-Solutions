// ccf-csp 201512-2

#include <iostream>
#include <vector>

using namespace std;

int a[31][31]{0};
bool is_clear[31][31]{false};

int main() {
    ios::sync_with_stdio(false);
    int n{}, m{};
    cin >> n >> m;
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    // 横着来
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m - 2; ++j) {
            if (a[i][j] == a[i][j + 1] and a[i][j + 1] == a[i][j + 2]) {
                is_clear[i][j] = true;
                is_clear[i][j + 1] = true;
                is_clear[i][j + 2] = true;
            }
        }
    }
    // 竖着来
    for (int j{}; j < m; ++j) {
        for (int i{}; i < n - 2; ++i) {
            if (a[i][j] == a[i + 1][j] and a[i + 1][j] == a[i + 2][j]) {
                is_clear[i][j] = true;
                is_clear[i + 1][j] = true;
                is_clear[i + 2][j] = true;
            }
        }
    }
    // 输出
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            if (!is_clear[i][j]) {
                cout << a[i][j] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
