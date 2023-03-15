// ccf-csp 201612-1

#include <iostream>
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
    int flag{-1};
    for (int i{}; i < n; ++i) {
        int smaller{}, greater{};
        for (int j{}; j < n; ++j) {
            if (a[j] < a[i]) {
                smaller++;
            } else if (a[j] > a[i]) {
                greater++;
            }
        }
        if (smaller == greater) {
            flag = a[i];
            break;
        }
    }
    cout << flag << endl;
    delete[] a;
    return 0;
}
