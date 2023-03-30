// ccf csp 01

#include <iostream>

using namespace std;

int area{};
int field[10001][10001]{};

int main() {
    ios::sync_with_stdio(false);
    int n{}, a{}, b{};
    cin >> n >> a >> b;
    for (int i{}; i < n; ++i) {
        int x1{}, y1{}, x2{}, y2{};
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j{}; j < x2 - x1; ++j) {
            for (int k{}; k < y2 - y1; ++k) {
                if (x1 + j >= 0 and x1 + j < x2 and y1 + k >= 0 and y1 + k < y2) {
                    field[x1 + j][y1 + k]++;
                }
            }
        }
    }

    for (int i{}; i < a; ++i) {
        for (int j{}; j < b; ++j) {
            if (field[i][j] != 0) {
                area++;
            }
        }
    }
    cout << area << endl;
    return 0;
}
