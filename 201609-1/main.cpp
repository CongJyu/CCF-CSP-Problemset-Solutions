// ccf-csp 201609-1

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
    int delta{}, current;
    for (int i{1}; i < n; ++i) {
        current = abs(a[i] - a[i - 1]);
        if (delta < current) {
            delta = current;
        }
    }
    cout << delta << endl;
    delete[] a;
    return 0;
}
