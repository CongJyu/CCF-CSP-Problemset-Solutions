// ccf-csp 201709-1

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int current{n / 10}, total{n / 10};
    while (current >= 5) {
        current -= 5;
        total += 2;
    }
    while (current >= 3 and current < 5) {
        current -= 3;
        total++;
    }
    cout << total << endl;
    return 0;
}
