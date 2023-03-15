// ccf-csp 202203-1

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{}, k{};
    cin >> n >> k;
    int *a{new int[n + 1]};
    a[0] = 1;
    for (int i{1}; i < n; ++i) {
        a[i] = -1;
    }
    int cnt_sentence{};
    while (k--) {
        long long x{}, y{};
        cin >> x >> y;
        if (a[y] == -1) {
            cnt_sentence++;
            clog << "x = " << x << ", y = " << y << endl;
        }
        a[x] = 1;
    }
    cout << cnt_sentence << endl;
    delete[] a;
    return 0;
}
