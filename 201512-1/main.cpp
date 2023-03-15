// ccf-csp 201512-1

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string num;
    cin >> num;
    int sum{};
    for (int i{}; i < (int) num.length(); ++i) {
        sum += num[i] - '0';
    }
    cout << sum << endl;
    return 0;
}
