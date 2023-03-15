// csp 201403-1

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int *a{new int[n]};
    int cnt{};
    for (int i{}; i < n; ++i) {
        cin >> a[i];
        for (int j{}; j < i; ++j) {
            if (a[j] == -a[i]) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    delete[] a;
    return 0;
}
