// ccf-csp 201409-3

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string target;
    cin >> target;
    int cap_true{};
    cin >> cap_true;
    int n{};
    cin >> n;
    while (n--) {
        string input;
        cin >> input;
        if (cap_true == 1) {
            // 大小写敏感
            if (input.find(target) != string::npos) {
                cout << input << endl;
            }
        } else {
            // 大小写不敏感
            string tran_input{input};
            transform(target.begin(), target.end(), target.begin(), ::tolower);
            transform(tran_input.begin(), tran_input.end(), tran_input.begin(), ::tolower);
            if (tran_input.find(target) != string::npos) {
                cout << input << endl;
            }
        }
    }
    return 0;
}
