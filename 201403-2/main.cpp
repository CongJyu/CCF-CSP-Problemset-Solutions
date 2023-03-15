// ccf-csp 201403-2

#include <iostream>

using namespace std;

const int N{10};

struct Windows {
    int window_num;
    int x1, y1, x2, y2;
};

struct Point {
    int x, y;
};

Windows win[N];
Point p[N];
int order[N];

int main() {
    ios::sync_with_stdio(false);
    int n{}, m{};
    cin >> n >> m;
    for (int i{}; i < n; ++i) {
        win[i].window_num = i + 1;
        cin >> win[i].x1 >> win[i].y1 >> win[i].x2 >> win[i].y2;
    }
    for (int i{}; i < m; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    for (int i{}; i < n; ++i) {
        order[i] = n - i - 1;
    }
    int win_num, tmp;
    for (int i{}; i < m; ++i) {
        win_num = -1;
        for (int j{}; j < n; ++j) {
            if (win[order[j]].x1 <= p[i].x and p[i].x <= win[order[j]].x2 and
                win[order[j]].y1 <= p[i].y and p[i].y <= win[order[j]].y2) {
                win_num = win[order[j]].window_num;
                tmp = order[j];
                for (int k{j}; k > 0; --k) {
                    order[k] = order[k - 1];
                }
                order[0] = tmp;
                break;
            }
        }
        if (win_num == -1) {
            cout << "IGNORED" << endl;
        } else {
            cout << win_num << endl;
        }
    }
    return 0;
}
