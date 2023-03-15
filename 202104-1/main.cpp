// ccf-csp 202104-1

#include <iostream>

using namespace std;

int a[501][501]{};

int main() {
    ios::sync_with_stdio(false);
    int n{}, m{}, l{};
    cin >> n >> m >> l;
    int *h{new int[l]};
    for (int i{}; i < l; ++i) {
        h[i] = 0;
    }
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            cin >> a[i][j];
            h[a[i][j]]++;
        }
    }
    for (int i{}; i < l; ++i) {
        cout << h[i] << " ";
    }
    cout << endl;
    delete[] h;
    return 0;
}
