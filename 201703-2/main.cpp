// ccf-csp 201703-2

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int *a{new int[n]};
    for (int i{}; i < n; ++i) {
        a[i] = i + 1;
    }
    int m{};
    cin >> m;
    while (m--) {
        int p{}, q{};
        cin >> p >> q;
        int tmp{}, flag{};
        for (int i{}; i < n; ++i) {
            if (a[i] == p) {
                tmp = a[i];
                flag = i;
                break;
            }
        }
        if (q > 0) {
            for (int i{flag + 1}; i <= flag + q; ++i) {
                a[i - 1] = a[i];
            }
            a[flag + q] = tmp;
            for (int i{}; i < n; ++i) {
                clog << a[i] << " ";
            }
            clog << endl;
        } else {
            for (int i{flag}; i >= flag + q; --i) {
                a[i] = a[i - 1];
            }
            a[flag + q] = tmp;
            for (int i{}; i < n; ++i) {
                clog << a[i] << " ";
            }
            clog << endl;
        }
    }
    for (int i{}; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    return 0;
}
