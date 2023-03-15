// ccf-csp 201712-1

#include <iostream>
#include <algorithm>

using namespace std;

int a[10001]{};

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    for (int i{}; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int delta{100001};
    for (int i{1}; i < n; ++i) {
        if (a[i] - a[i - 1] < delta) {
            delta = a[i] - a[i - 1];
        }
    }
    cout << delta << endl;
    return 0;
}
