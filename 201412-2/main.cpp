// ccf-csp 201412-2

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int **a{new int *[n]};
    for (int i{}; i < n; ++i) {
        a[i] = new int[n];
    }
    for (int i{}; i < n; ++i) {
        for (int j{}; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    // 左上部分
    int x{}, y{};
    for (int i{}; i < n; ++i) {
        if (i & 1) {
            for (int j{}; j < i; ++j) {
                cout << a[x][y] << " ";
                x++;
                y--;
            }
            cout << a[x][y] << " ";
            x++;
        } else {
            for (int j{}; j < i; ++j) {
                cout << a[x][y] << " ";
                x--;
                y++;
            }
            cout << a[x][y] << " ";
            y++;
        }
    }
    // 右下部分
    if (n & 1) {
        y--;
        x++;
    } else {
        y++;
        x--;
    }
    for (int i{n - 2}; i > 0; --i) {
        if ((i & 1) != 0) {
            for (int j{}; j < i; ++j) {
                cout << a[x][y] << " ";
                x++;
                y--;
            }
            cout << a[x][y] << " ";
            y++;
        } else {
            for (int j{}; j < i; ++j) {
                cout << a[x][y] << " ";
                x--;
                y++;
            }
            cout << a[x][y] << " ";
            x++;
        }
    }
    if (n != 1) {
        cout << a[n - 1][n - 1] << endl;
    }
    delete[] a;
    return 0;
}
