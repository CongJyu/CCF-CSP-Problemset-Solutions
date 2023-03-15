// ccf-csp 201312-3

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int *a{new int[n]};
    for (int i{}; i < n; ++i) {
        cin >> a[i];
    }
    int min_v, tmp, area{};
    for (int i{}; i < n; ++i) {
        min_v = a[i];
        for (int j{i}; j < n; ++j) {
            if (min_v > a[j]) {
                min_v = a[j];
            }
            tmp = (j - i + 1) * min_v;
            if (tmp > area) {
                area = tmp;
            }
        }
    }
    cout << area << endl;
    delete[] a;
    return 0;
}
