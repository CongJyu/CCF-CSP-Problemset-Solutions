// ccf csp 202203-1

#include <iostream>

using namespace std;

int yy[10001];

int main() {
    ios::sync_with_stdio(false);
    int n{}, k{};
    cin >> n >> k;
    int x{}, y{}, counter{};
    for (int i{}; i < k; ++i) {
        cin >> x >> y;
        if (y != 0 and yy[y] == 0) {
            counter++;
        }
        yy[x] = 1;
    }
    cout << counter << endl;
    return 0;
}
