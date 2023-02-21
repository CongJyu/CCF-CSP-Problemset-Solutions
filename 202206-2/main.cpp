// ccf csp 202206-2

#include <iostream>

using namespace std;

int map[60][60] = {0};

int main() {
    ios::sync_with_stdio(false);
    int n{}, l{}, s{};
    cin >> n >> l >> s;  // CCF 島上面嘅樹嘅數目，綠化圖大小，寶藏圖大小
    int *x{new int[n]}, *y{new int[n]};
    for (int i{}; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i{s}; i >= 0; --i) {
        for (int j{}; j < s + 1; ++j) {
            cin >> map[i][j];
        }
    }
    
    delete[] x;
    delete[] y;
    return 0;
}
