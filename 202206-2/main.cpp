// ccf-csp 202206-2

#include <iostream>
#include <map>

using namespace std;

int a[1005][2]{}, b[52][52]{};
map<int, map<int, int> > mp;

int main() {
    ios::sync_with_stdio(false);
    int n{}, l{}, s{};
    cin >> n >> l >> s;
    for (int i{}; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        mp[a[i][0]][a[i][1]] = 1;
    }
    for (int i{s}; i >= 0; --i) {
        for (int j{}; j <= s; ++j) {
            cin >> b[i][j];
        }
    }
    int cnt{};
    for (int i{}; i < n; ++i) {
        bool flag{true};
        int x{a[i][0]}, y{a[i][1]};
        for (int j{}; j <= s; ++j) {
            for (int k{}; k <= s; ++k) {
                if (x + j > l or y + k > l or b[j][k] != mp[x + j][y + k]) {
                    flag = false;
                    goto level_1;
                }
            }
        }
        level_1:
        if (flag) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
