// csp 201412-1

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{}, tmp{};
    cin >> n;
    int times[1001]{0};
    for (int i{}; i < n; ++i) {
        cin >> tmp;
        times[tmp]++;
        cout << times[tmp] << " ";
    }
    cout << endl;
    return 0;
}
