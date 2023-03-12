// ccf csp 201312-4

#include <iostream>

using namespace std;

long long n{};
long long b[1005][10];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (long long i{1}; i <= n; ++i) {
        b[i][0] = 1;
        b[i][1] = (b[i - 1][0] + b[i - 1][1] * 2) % 1000000007;
        b[i][2] = (b[i - 1][0] + b[i - 1][2]) % 1000000007;
        b[i][3] = (b[i - 1][1] + b[i - 1][2] + b[i - 1][3] * 2) % 1000000007;
        b[i][4] = (b[i - 1][1] + b[i - 1][4] * 2) % 1000000007;
        b[i][5] = (b[i - 1][3] + b[i - 1][4] + b[i - 1][5] * 2) % 1000000007;
    }
    cout << b[n][5] << endl;
    return 0;
}
