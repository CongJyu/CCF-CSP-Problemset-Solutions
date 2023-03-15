// ccf-csp 201912-2

#include <iostream>
#include <vector>

using namespace std;

struct Position {
    long long x;
    long long y;
};

int grade[5]{};

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    Position *p{new Position[n]};
    for (int i{}; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    vector<Position> pp;
    for (int i{}; i < n; ++i) {
        bool up{false}, down{false}, left{false}, right{false};
        for (int j{}; j < n; ++j) {
            if (p[i].x == p[j].x and p[i].y + 1 == p[j].y) {
                up = true;
            }
            if (p[i].x == p[j].x and p[i].y - 1 == p[j].y) {
                down = true;
            }
            if (p[i].x + 1 == p[j].x and p[i].y == p[j].y) {
                left = true;
            }
            if (p[i].x - 1 == p[j].x and p[i].y == p[j].y) {
                right = true;
            }
        }
        if (up and down and left and right) {
            pp.push_back(p[i]);
        }
    }
    for (int i{}; i < (int) pp.size(); ++i) {
        int score{};
        for (int j{}; j < n; ++j) {
            if (pp.at(i).x == p[j].x - 1 and pp.at(i).y == p[j].y - 1) {
                score++;
            }
            if (pp.at(i).x == p[j].x - 1 and pp.at(i).y == p[j].y + 1) {
                score++;
            }
            if (pp.at(i).x == p[j].x + 1 and pp.at(i).y == p[j].y - 1) {
                score++;
            }
            if (pp.at(i).x == p[j].x + 1 and pp.at(i).y == p[j].y + 1) {
                score++;
            }
        }
        grade[score]++;
    }
    for (int i{}; i < 5; ++i) {
        cout << grade[i] << endl;
    }
    delete[] p;
    return 0;
}
