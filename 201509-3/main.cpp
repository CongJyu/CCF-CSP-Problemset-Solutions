// ccf-csp 201509-3

#include <iostream>
#include <string>

using namespace std;

string mo[110], str_val[110], str_name[110];

int main() {
    ios::sync_with_stdio(false);
    int m{}, n{};
    cin >> m >> n;
    cin.get();
    char temp[110];
    for (int i{}; i < m; ++i) {
        gets(temp);
        mo[i] = temp;
    }
    for (int i{}; i < m; ++i) {
        int pos{(int) mo[i].find("{{ ")};
        while (mo[i].find("{{ ") != string::npos) {
            bool find{false};
            int pos_r{(int) mo[i].find((" }}"))};
            int len{pos_r - pos + 3};
            int len_name{pos_r - (pos + 3)};
            string tmp{mo[i].substr(pos + 3, len_name)};
            int j;
            for (j = 0; j < n; ++j) {
                if (tmp == str_name[j]) {
                    find = true;
                    mo[i].replace(pos, len, str_val[j]);
                    break;
                }
            }
            if (!find) {
                mo[i].erase(pos, len);
                pos = (int) mo[i].find("{{ ", pos + 1);
            } else {
                pos = (int) mo[i].find("{{ ", pos + str_val[j].size() - 1);
            }
        }
    }
    for (int i{}; i < m; ++i) {
        cout << mo[i] << endl;
    }
    return 0;
}
