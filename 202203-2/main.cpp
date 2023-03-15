// ccf-csp 202203-2

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{}, m{}, k{};
    cin >> n >> m >> k;
    int *t{new int[n]}, *c{new int[n]};
    for (int i{}; i < n; ++i) {
        cin >> t[i] >> c[i];
    }
    while (m--) {
        int query{};
        cin >> query;
        int yes_go{};
        for (int i{}; i < n; ++i) {
            if (query + k - t[i] <= 0 and t[i] - (query + k) < c[i]) {
                yes_go++;
                clog << i + 1 << endl;
            }
        }
        cout << yes_go << endl;
    }
    return 0;
}
