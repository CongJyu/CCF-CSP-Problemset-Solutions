// ccf-csp 201903-1

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int *a{new int[n]};
    for (int i{}; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    if (n % 2 == 0) {
        cout << a[n - 1] << " ";
        if ((a[n / 2 - 1] + a[n / 2]) % 2 == 0) {
            cout << fixed << setprecision(1) << (a[n / 2 - 1] + a[n / 2]) / 2 << " ";
        } else {
            cout << fixed << setprecision(1) << (a[n / 2 - 1] + a[n / 2]) / 2.0 << " ";
        }
        cout << a[0];
    } else {
        cout << a[n - 1] << " " << a[n / 2] << " " << a[0] << endl;
    }
    delete[] a;
    return 0;
}
