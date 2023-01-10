// ccf csp 202209-2

#include <algorithm>
#include <iostream>

using namespace std;

int pack[(int) 1e7];

int main() {
    ios::sync_with_stdio(false);
    int n{}, x{};
    cin >> n >> x;
    int *a{new int[n]}, sum{};
    for (int i{}; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    // one dimension 01 backpack
    for (int i{}; i < n; ++i) {
        for (int j{sum}; j >= a[i]; --j) {
            pack[j] = max(pack[j], pack[j - a[i]] + a[i]);
        }
    }
    // find min value
    for (int i{x}; i <= sum; ++i) {
        if (pack[i] >= x) {
            cout << pack[i];
            break;
        }
    }
    return 0;
}
