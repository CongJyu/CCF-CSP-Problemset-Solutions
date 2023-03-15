// ccf-csp 201509-1

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
    int cnt{1};
    for (int i{1}; i < n; ++i) {
        if (a[i - 1] != a[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    delete[] a;
    return 0;
}
