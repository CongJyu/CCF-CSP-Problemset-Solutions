// ccf csp 202203-2

#include <iostream>
#include <cmath>

using namespace std;

int t[200002], c[200002], q, left_board[200002], right_board[200002];

int main() {
    ios::sync_with_stdio(false);
    int n{}, m{}, k{};
    cin >> n >> m >> k;
    for (int i{1}; i <= n; ++i) {
        cin >> t[i] >> c[i];
        // left_board[i] = max(0, t[i] - c[i] - k + 1);
        // right_board[i] = t[i] - k + 1;
    }
    for (int i{1}; i <= m; ++i) {
        cin >> q;
        int counter{};
        for (int j{1}; j <= n; ++j) {
            if (q + k + c[j] > t[j] and q + k <= t[j]) {
                counter++;
            }
        }
        cout << counter << endl;
    }
    return 0;
}
