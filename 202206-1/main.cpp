// ccf csp 202206-1

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double func(int a_i, double a_ave, double d_a) {
    return (a_i - a_ave) / sqrt(d_a);
}

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int *a{new int[n]};
    double sum{};
    for (int i{}; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    double ave{sum / n};
    double d{};
    for (int i{}; i < n; ++i) {
        d += (a[i] - ave) * (a[i] - ave);
    }
    d /= n;
    for (int i{}; i < n; ++i) {
        cout << fixed << setprecision(9) << func(a[i], ave, d) << endl;
    }
    delete[] a;
    return 0;
}
