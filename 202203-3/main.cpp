// ccf-csp 202203-3

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{}, m{};
    cin >> n >> m;
    int *l{new int[n]};
    for (int i{}; i < n; ++i) {
        cin >> l[i];
    }
    int g{};
    cin >> g;
    long long *f{new long long[g]}, *a{new long long[g]}, *na{new long long[g]},
            *pa{new long long[g]}, *paa{new long long[g]}, *paar{new long long[g]};
    for (int i{}; i < g; ++i) {
        cin >> f[i] >> a[i] >> na[i] >> pa[i] >> paa[i] >> paar[i];

    }
    return 0;
}
