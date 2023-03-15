// ccf-csp 201912-1

#include <iostream>
#include <string>

using namespace std;

int a[4]{};

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    int i{1}, cnt{1};
    while (true) {
        if (cnt > n) {
            break;
        }
        if ((i % 7 == 0) or (to_string(i).find('7') != string::npos)) {
            a[(i - 1) % 4]++;
            clog << "a[" << (i - 1) % 4 << "] 跳过 " << i << endl;
        } else {
            cnt++;
        }
        i++;
    }
    for (int j{}; j < 4; ++j) {
        cout << a[j] << endl;
    }
    return 0;
}
