// ccf-csp 202104-2

#include <iostream>

using namespace std;

int a[601][601]{};

int main() {
    ios::sync_with_stdio(false);
    int n{}, l{}, r{}, t{};
    cin >> n >> l >> r >> t;
    for (int i{}; i < n; ++i) {
        for (int j{}; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    // no idea
    return 0;
}
