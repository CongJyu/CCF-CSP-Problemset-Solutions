// ccf-csp 202006-1

#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    char type;
};

int main() {
    ios::sync_with_stdio(false);

    int n{}, m{};
    cin >> n >> m;
    Point *p{new Point[n]};
    vector<Point> aa;
    vector<Point> bb;

    for (int i{}; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].type;
        if (p[i].type == 'A') {
            aa.push_back(p[i]);
        } else {
            bb.push_back(p[i]);
        }
    }

    while (m--) {
        int theta_0{}, theta_1{}, theta_2{};
        cin >> theta_0 >> theta_1 >> theta_2;

        // vector a
        int a_up{}, a_down{};
        for (int i{}; i < (int) aa.size(); ++i) {
            if (theta_0 + theta_1 * aa.at(i).x + theta_2 * aa.at(i).y > 0) {
                a_up++;
            } else {
                a_down++;
            }
        }
        // vector b
        int b_up{}, b_down{};
        for (int i{}; i < (int) bb.size(); ++i) {
            if (theta_0 + theta_1 * bb.at(i).x + theta_2 * bb.at(i).y > 0) {
                b_up++;
            } else {
                b_down++;
            }
        }

        if ((a_up == 0 and b_down == 0) or (a_down == 0 and b_up == 0)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
