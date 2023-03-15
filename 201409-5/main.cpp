// ccf-csp 201409-5
// got 10 points

#include <iostream>

using namespace std;

const int mod{1000000007};

int main() {
    ios::sync_with_stdio(false);
    clog << mod << endl;
    int n{}, m{};
    cin >> n >> m;
    int block{n * m / 6};
    int result{1};
    for (int i{}; i < block; ++i) {
        result *= 2;
        result %= mod;
    }
    cout << result << endl;
    return 0;
}
