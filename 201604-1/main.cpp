// ccf-csp 201604-1

#include <iostream>

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
    for (int i{1}; i < n - 1; ++i) {
        if ((a[i - 1] > a[i] and a[i] < a[i + 1]) or (a[i - 1] < a[i] and a[i] > a[i + 1])) {
            cnt++;
        }
    }
    cout << cnt << endl;
    delete[] a;
    return 0;
}
