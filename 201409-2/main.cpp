// ccf-csp 201409-2

#include <iostream>

using namespace std;

int draw[101][101]{0};

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    while (n--) {
        int x1{}, y1{}, x2{}, y2{};
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i{x1 + 1}; i <= x2; ++i) {
            for (int j{y1 + 1}; j <= y2; ++j) {
                draw[i][j] = 1;
            }
        }
    }
    int cnt{};
    for (int i{}; i < 101; ++i) {
        for (int j{}; j < 101; ++j) {
            if (draw[i][j] == 1) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
