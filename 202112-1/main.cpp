// ccf-csp 202112-1

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{}, N{};
    cin >> n >> N;
    int *a{new int[n + 2]};
    a[0] = 0;
    a[n + 1] = N;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
    }
    int sum{};
    for (int i{1}; i <= n + 1; ++i) {
        sum += (a[i] - a[i - 1]) * (i - 1);
    }
    delete[] a;
    cout << sum << endl;
    return 0;
}
