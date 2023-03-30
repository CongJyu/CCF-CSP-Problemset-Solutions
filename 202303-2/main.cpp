// ccf csp 02

#include <iostream>
#include <algorithm>

using namespace std;

struct Field {
    int t;
    int c;
} f[100001];
int day[100001];

bool cmp(Field a, Field b) {
    if (a.t != b.t) {
        return a.t < b.t;
    } else {
        return a.c < b.c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n{}, m{}, k{};
    cin >> n >> m >> k;
    for (int i{}; i < n; ++i) {
        cin >> f[i].t >> f[i].c;
    }
    sort(f, f + n, cmp);
    int res_total{}, time{};
    bool done{false};
    while (!done) {
        int counter{};
        for (int i{n - 1}; i >= 0; --i) {
            res_total += (f[i].t - f[counter].t) * f[i].c;
        }
        if (res_total <= m) {
            done = true;
            time = f[0].t;
            break;
        } else {
            counter++;
            res_total = 0;
        }
    }
    int sum_res{};
    for (int i{}; i < n; ++i) {
        sum_res += f[i].c;
        day[i] = time;
    }
    time -= (m - res_total) / sum_res;
    if (time < k) {
        time = k;
    }
    cout << time << endl;
    return 0;
}
