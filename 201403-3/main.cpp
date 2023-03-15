// ccf-csp 201403-3

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string ask;
    cin >> ask;
    map<char, int> mp;
    for (int i{}; i < (int) ask.size(); ++i) {
        if (i + 1 < (int) ask.size() and ask.at(i + 1) == ':') {
            mp[ask[i]] = 2;
            i++;
        } else {
            mp[ask[i]] = 1;
        }
    }

    int n{};
    cin >> n;
    cin.ignore();

    string cmd, t;
    for (int i{}; i < n; ++i) {
        getline(cin, cmd);
        stringstream ss(cmd);
        cout << "Case " << i + 1 << ": ";

        vector<string> v;
        map<char, string> res;

        while (ss >> t) {
            v.push_back(t);
        }
        for (int j{1}; j < (int) v.size(); ++j) {
            string tmp{v[j]};
            if (tmp.size() == 2 and tmp[0] == '-' and islower(tmp[1])) {
                char ch{tmp.at(1)};
                if (mp[ch] == 1) {
                    res[ch] = "**";
                } else if (mp[ch] == 2 and j + 1 < (int) v.size()) {
                    res[ch] = v[j + 1];
                    j++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        for (const auto &x: res) {
            cout << "-" << x.first << " ";
            if (x.second != "**") {
                cout << x.second << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
