// ccf-csp 202012-1

#include <iostream>

using namespace std;

void relu(long long x) {
    if (x > 0) {
        cout << x << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    long long *w{new long long[n]}, *score{new long long[n]};
    long long sigma{};
    for (int i{}; i < n; ++i) {
        cin >> w[i] >> score[i];
        sigma += w[i] * score[i];
    }
    relu(sigma);
    delete[] w;
    delete[] score;
    return 0;
}
