// csp 201409-1

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int *a{new int[n]};
    for (int i{}; i < n; ++i) {
        cin >> a[i];
    }
    int cnt{};
    for (int i{}; i < n - 1; ++i) {
        for (int j{i + 1}; j < n; ++j) {
            if (abs(a[i] - a[j]) == 1) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    delete[] a;
    return 0;
}
