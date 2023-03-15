// ccf-csp 201703-1

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{}, k{};
    cin >> n >> k;
    int *a{new int[n]};
    for (int i{}; i < n; ++i) {
        cin >> a[i];
    }
    // sort(a, a + n);
    int cake{}, cnt{};
    for (int i{}; i < n; ++i) {
        if (cake >= k) {
            cnt++;
            cake = 0;
        }
        cake += a[i];
    }
    if (cake > 0) {
        cnt++;
    }
    cout << cnt << endl;
    delete[] a;
    return 0;
}
