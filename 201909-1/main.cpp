// ccf-csp 201909-1

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n{}, m{};
    cin >> n >> m;
    int *origin_apple{new int[n]};
    int *cut{new int[n]};
    for (int i{}; i < n; ++i) {
        cut[i] = 0;
    }
    for (int i{}; i < n; ++i) {
        cin >> origin_apple[i];
        for (int j{}; j < m; ++j) {
            int tmp{};
            cin >> tmp;
            cut[i] += tmp;
        }
    }
    int apple_left{};
    for (int i{}; i < n; ++i) {
        apple_left += (origin_apple[i] + cut[i]);
    }

    int largest_cut{100000}, pos{};
    for (int i{}; i < n; ++i) {
        if (cut[i] < largest_cut) {
            largest_cut = cut[i];
            pos = i + 1;
        }
    }

    cout << apple_left << " " << pos << " " << abs(largest_cut) << endl;

    delete[] cut;
    delete[] origin_apple;
    return 0;
}
