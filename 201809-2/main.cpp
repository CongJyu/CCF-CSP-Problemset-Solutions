// ccf-csp 201809-2

#include <iostream>

using namespace std;

int time_axis[1000000]{};

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int *a{new int[n]}, *b{new int[n]}, *c{new int[n]}, *d{new int[n]};
    for (int i{}; i < n; ++i) {
        // ab
        cin >> a[i] >> b[i];
        for (int j{a[i]}; j < b[i]; ++j) {
            time_axis[j]++;
        }
    }
    for (int i{}; i < n; ++i) {
        // cd
        cin >> c[i] >> d[i];
        for (int j{c[i]}; j < d[i]; ++j) {
            time_axis[j]++;
        }
    }
    int cnt{};
    for (int i{1}; i < max(b[n - 1], d[n - 1]); ++i) {
        clog << time_axis[i] << " ";
        if (time_axis[i] > 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;
    return 0;
}
