// csp 201312-1

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int *a{new int[n]};
    int cnt[100000]{0};
    for (int i{}; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int tmp_max{-1}, flag{};
    for (int i{}; i < 100000; ++i) {
        if (cnt[i] > tmp_max) {
            tmp_max = cnt[i];
            flag = i;
        }
    }
    cout << flag << endl;
    delete[] a;
    return 0;
}
