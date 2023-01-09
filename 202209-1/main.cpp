// ccf csp 202209-1

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{}, m{};
    cin >> n >> m;
    int *a{new int[n + 1]};
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
    }
    int *c{new int[n + 1]};
    for (int i{}; i <= n; ++i) {
        c[i] = 1;
    }
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= i; ++j) {
            c[i] *= a[j];
        }
    }
    int *b{new int[n + 1]};
    b[0] = 1;
    for (int i{1}; i <= n; ++i) {
        if (i == 1) {
            b[i] = (m % c[i]) / c[0];
        } else {
            b[i] = ((m % c[i]) - (m % c[i - 1])) / c[i - 1];
        }
    }
    for (int i{1}; i <= n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}
