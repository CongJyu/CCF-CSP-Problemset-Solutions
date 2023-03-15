// csp 201503-1

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{}, m{};
    cin >> n >> m;
    int **g{new int *[n]};
    for (int i{}; i < n; ++i) {
        g[i] = new int[m];
    }
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    for (int j{m - 1}; j >= 0; --j) {
        for (int i{}; i < n; ++i) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    delete[] g;
    cout << endl;
    return 0;
}
