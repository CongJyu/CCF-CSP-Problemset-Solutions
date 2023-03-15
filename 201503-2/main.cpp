// ccf-csp 201503-2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Num {
    int number;
    int time;
};

bool cmp(Num x, Num y) {
    if (x.time != y.time) {
        return x.time > y.time;
    } else {
        return x.number < y.number;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    vector<Num> a;
    for (int i{}; i < n; ++i) {
        int input{};
        cin >> input;
        if (a.empty()) {
            a.push_back({input, 1});
        } else {
            bool found{false};
            for (int j{}; j < (int) a.size(); ++j) {
                if (a.at(j).number == input) {
                    found = true;
                    a.at(j).time++;
                    break;
                }
            }
            if (!found) {
                a.push_back({input, 1});
            }
        }
    }
    sort(a.begin(), a.end(), cmp);
    for (int i{}; i < (int) a.size(); ++i) {
        cout << a.at(i).number << " " << a.at(i).time << endl;
    }
    return 0;
}
