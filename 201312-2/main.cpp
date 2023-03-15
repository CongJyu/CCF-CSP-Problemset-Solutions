// ccf-csp 201312-2

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    clog << s << endl;
    int reg{
            ((s[0] - '0') * 1 + (s[2] - '0') * 2 + (s[3] - '0') * 3 + (s[4] - '0') * 4 + (s[6] - '0') * 5 +
             (s[7] - '0') * 6 + (s[8] - '0') * 7 + (s[9] - '0') * 8 + (s[10] - '0') * 9) % 11
    };
    bool ok;
    if (reg != 10) {
        if (reg == s[12] - '0') {
            ok = true;
        } else {
            ok = false;
        }
    } else {
        if (s[12] == 'X') {
            ok = true;
        } else {
            ok = false;
        }
    }
    if (ok) {
        cout << "Right" << endl;
    } else {
        if (reg == 10) {
            for (int i{}; i < 12; ++i) {
                cout << s[i];
            }
            cout << "X" << endl;
        } else {
            for (int i{}; i < 12; ++i) {
                cout << s[i];
            }
            cout << reg << endl;
        }
    }
    return 0;
}
