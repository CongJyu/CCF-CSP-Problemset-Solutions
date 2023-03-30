// ccf csp 03

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct Att {
    int attribute;
    int value;
};

struct User {
    int dn;
    Att usr_att[501];
} usr[100001];

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;  // user number
    for (int i{}; i < n; ++i) {
        cin >> usr[i].dn;
        // clog << "CLOG: " << usr[i].dn << endl;
        int at_num{};
        cin >> at_num;
        for (int j{}; j < at_num; ++j) {
            cin >> usr[i].usr_att[j].attribute
                >> usr[i].usr_att[j].value;
        }
    }
    int m{};
    cin >> m;  // number of expressions
    for (int i{}; i < m; ++i) {
        string exp;
        cin >> exp;
        if (exp[0] == '&' or exp[0] == '|') {
            // combined expression
            if (exp[0] == '&') {
                // and
                string exp1, exp2;
                bool start{false};
                int flag1{};
                char op1;
                for (int j{}; j < exp.length(); ++j) {
                    if (start) {
                        exp1 += exp[j];
                    }
                    if (exp[j] == '(') {
                        start = true;
                    } else if (exp[j] == ')') {
                        start = false;
                    }
                }
            } else {
                // or
            }
        } else {
            string attr_s, value_s;
            int flag{};
            char op;
            // atomic expression
            for (int j{}; j < exp.length(); ++j) {
                if (exp[j] >= '0' and exp[j] <= '9') {
                    attr_s += exp[j];
                } else {
                    flag = j + 1;
                    op = exp[j];
                    break;
                }
            }
            // clog << "CLOG: OP " << op << endl;
            for (int j{flag}; j < exp.length(); ++j) {
                if (exp[j] >= '0' and exp[j] <= '9') {
                    value_s += exp[j];
                }
            }
            // clog << attr_s << " " << value_s << endl;
            int attr_i{stoi(attr_s)};
            int value_i{stoi(value_s)};
            // clog << attr_s << " " << value_s << endl;
            if (op == ':') {
                // find dn
                for (int k{}; k < n; ++k) {
                    for (int l{}; l < 501; ++l) {
                        if (usr[k].usr_att[l].attribute == attr_i and
                            usr[k].usr_att[l].value == value_i) {
                            cout << usr[k].dn << " ";
                        }
                    }
                }
                cout << endl;
            } else {
                // find dn, not equal
                for (int k{}; k < n; ++k) {
                    for (int l{}; l < 501; ++l) {
                        if (usr[k].usr_att[l].attribute == attr_i and
                            usr[k].usr_att[l].value != value_i) {
                            cout << usr[k].dn << " ";
                        }
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
