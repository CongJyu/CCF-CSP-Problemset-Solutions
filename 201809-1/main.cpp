// ccf-csp 201809-1

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int *a{new int[n]}, *b{new int[n]};
    for (int i{}; i < n; ++i) {
        cin >> a[i];
    }
    b[0] = (a[0] + a[1]) / 2;
    b[n - 1] = (a[n - 1] + a[n - 2]) / 2;
    for (int i{1}; i < n - 1; ++i) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
    }
    for (int i{}; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
    delete[] a;
    delete[] b;
    return 0;
}
