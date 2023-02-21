// ccf csp 202212-1

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{};  // number of years
    double i{};  // profit rate
    cin >> n >> i;
    double saving{};  // saving in the bank
    for (int counter{}; counter <= n; ++counter) {
        int temp{};
        cin >> temp;
        saving += temp * pow(i + 1, -counter);
    }
    cout << saving << endl;
    return 0;
}
