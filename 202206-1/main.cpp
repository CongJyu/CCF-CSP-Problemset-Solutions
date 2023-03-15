// ccf-csp 202206-1

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    vector<int> a;
    for (int i{}; i < n; ++i) {
        int tmp_a{};
        cin >> tmp_a;
        a.push_back(tmp_a);
    }
    double average{};
    for (int i{}; i < n; ++i) {
        average += a.at(i);
    }
    average /= n;
    double dd{};
    for (int i{}; i < n; ++i) {
        dd += (a.at(i) - average) * (a.at(i) - average);
    }
    dd /= n;
    for (int i{}; i < n; ++i) {
        double result{(a.at(i) - average) / sqrt(dd)};
        cout << result << endl;
    }
    return 0;
}
