// ccf-csp 201412-3

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string opt;
    while (cin >> opt) {
        if (opt == "buy") {
            // 买单
            int p{}, s{};
            cin >> p >> s;
        } else if (opt == "sell") {
            // 卖单
            int p{}, s{};
            cin >> p >> s;
        } else if (opt == "cancel") {
            // 撤销
            int i{};
            cin >> i;
        }
    }
    return 0;
}
