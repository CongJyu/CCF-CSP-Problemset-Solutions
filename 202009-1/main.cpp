// ccf-csp 202009-1

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Checkpoint {
    int x;
    int y;
    int number;
    double distance;
};

bool cmp(Checkpoint a, Checkpoint b) {
    if (a.distance != b.distance) {
        return a.distance < b.distance;
    } else {
        return a.number < b.number;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n{}, xx{}, yy{};
    cin >> n >> xx >> yy;
    Checkpoint *c{new Checkpoint[n]};
    for (int i{}; i < n; ++i) {
        cin >> c[i].x >> c[i].y;
        c[i].number = i + 1;
        c[i].distance = sqrt((xx - c[i].x) * (xx - c[i].x) + (yy - c[i].y) * (yy - c[i].y));
    }
    sort(c, c + n, cmp);
    cout << c[0].number << endl << c[1].number << endl << c[2].number << endl;
    delete[] c;
    return 0;
}
