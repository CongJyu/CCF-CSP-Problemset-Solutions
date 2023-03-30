// ccf csp 03

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Att {
    long long attribute;
    long long value;
};

struct User {
    int dn;
    Att usr_att[501];
} usr[100001];

vector<long long> usr_dn;

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
                int flag{}, flag1{}, flag2{};
                char op1, op2;
                for (int j{}; j < exp.length(); ++j) {
                    if (start) {
                        exp1 += exp[j];
                    }
                    if (exp[j] == '(') {
                        start = true;
                    } else if (exp[j] == ')') {
                        start = false;
                        flag = j + 1;
                        break;
                    }
                }
                for (int j{flag}; j < exp.length(); ++j) {
                    if (start) {
                        exp2 += exp[j];
                    }
                    if (exp[j] == '(') {
                        start = true;
                    } else if (exp[j] == ')') {
                        start = false;
                        break;
                    }
                }
                bool condition1{false}, condition2{false};
                string attr_s1, value_s1, attr_s2, value_s2;
                // atomic expression
                // exp1
                for (int j{}; j < exp1.length(); ++j) {
                    if (exp1[j] >= '0' and exp1[j] <= '9') {
                        attr_s1 += exp1[j];
                    } else {
                        flag1 = j + 1;
                        op1 = exp1[j];
                        break;
                    }
                }
                // clog << "CLOG: OP1# " << op1 << endl;
                for (int j{flag1}; j < exp1.length(); ++j) {
                    if (exp1[j] >= '0' and exp1[j] <= '9') {
                        value_s1 += exp1[j];
                    }
                }

                int attr_i1{stoi(attr_s1)};
                int value_i1{stoi(value_s1)};
                // clog << "CLOG: 1# " << attr_i1 << " " << value_i1 << endl;

                // exp2
                for (int j{}; j < exp2.length(); ++j) {
                    if (exp2[j] >= '0' and exp2[j] <= '9') {
                        attr_s2 += exp2[j];
                    } else {
                        flag2 = j + 1;
                        op2 = exp2[j];
                        break;
                    }
                }
                // clog << "CLOG: OP2# " << op2 << endl;
                for (int j{flag2}; j < exp2.length(); ++j) {
                    if (exp2[j] >= '0' and exp2[j] <= '9') {
                        value_s2 += exp2[j];
                    }
                }

                int attr_i2{stoi(attr_s2)};
                int value_i2{stoi(value_s2)};
                // clog << "CLOG: 2# " << attr_i2 << " " << value_i2 << endl;

                if (op1 == ':' and op2 == ':') {
                    // ::
                    bool condition1{false}, condition2{false};
                    for (int k{}; k < n; ++k) {
                        for (int l{}; l < 501; ++l) {
                            if (usr[k].usr_att[l].attribute == attr_i1 and
                                usr[k].usr_att[l].value == value_i1) {
                                condition1 = true;
                            }
                            if (usr[k].usr_att[l].attribute == attr_i2 and
                                usr[k].usr_att[l].value == value_i2) {
                                condition2 = true;
                            }
                            if (condition1 and condition2) {
                                // cout << usr[k].dn << " ";
                                usr_dn.push_back(usr[k].dn);
                                condition1 = false;
                                condition2 = false;
                                break;
                            }
                        }
                    }
                    sort(usr_dn.begin(), usr_dn.end());
                    for (int v_i{}; v_i < usr_dn.size(); ++v_i) {
                        cout << usr_dn[v_i] << " ";
                    }
                    cout << endl;
                    usr_dn.clear();
                } else if (op1 == ':' and op2 == '~') {
                    // :~
                    bool condition1{false}, condition2{false};
                    for (int k{}; k < n; ++k) {
                        for (int l{}; l < 501; ++l) {
                            if (usr[k].usr_att[l].attribute == attr_i1 and
                                usr[k].usr_att[l].value == value_i1) {
                                condition1 = true;
                            }
                            if (usr[k].usr_att[l].attribute == attr_i2 and
                                usr[k].usr_att[l].value != value_i2) {
                                condition2 = true;
                            }
                            if (condition1 and condition2) {
                                // cout << usr[k].dn << " ";
                                usr_dn.push_back(usr[k].dn);
                                condition1 = false;
                                condition2 = false;
                                break;
                            }
                        }
                    }
                    sort(usr_dn.begin(), usr_dn.end());
                    for (int v_i{}; v_i < usr_dn.size(); ++v_i) {
                        cout << usr_dn[v_i] << " ";
                    }
                    cout << endl;
                    usr_dn.clear();
                } else if (op1 == '~' and op2 == ':') {
                    // ~:
                    bool condition1{false}, condition2{false};
                    for (int k{}; k < n; ++k) {
                        for (int l{}; l < 501; ++l) {
                            if (usr[k].usr_att[l].attribute == attr_i1 and
                                usr[k].usr_att[l].value != value_i1) {
                                condition1 = true;
                            }
                            if (usr[k].usr_att[l].attribute == attr_i2 and
                                usr[k].usr_att[l].value == value_i2) {
                                condition2 = true;
                            }
                            if (condition1 and condition2) {
                                // cout << usr[k].dn << " ";
                                usr_dn.push_back(usr[k].dn);
                                condition1 = false;
                                condition2 = false;
                                break;
                            }
                        }
                    }
                    sort(usr_dn.begin(), usr_dn.end());
                    for (int v_i{}; v_i < usr_dn.size(); ++v_i) {
                        cout << usr_dn[v_i] << " ";
                    }
                    cout << endl;
                    usr_dn.clear();
                } else if (op1 == '~' and op2 == '~') {
                    // ~~
                    bool condition1{false}, condition2{false};
                    for (int k{}; k < n; ++k) {
                        for (int l{}; l < 501; ++l) {
                            if (usr[k].usr_att[l].attribute == attr_i1 and
                                usr[k].usr_att[l].value != value_i1) {
                                condition1 = true;
                            }
                            if (usr[k].usr_att[l].attribute == attr_i2 and
                                usr[k].usr_att[l].value != value_i2) {
                                condition2 = true;
                            }
                            if (condition1 and condition2) {
                                // cout << usr[k].dn << " ";
                                usr_dn.push_back(usr[k].dn);
                                condition1 = false;
                                condition2 = false;
                                break;
                            }
                        }
                    }
                    sort(usr_dn.begin(), usr_dn.end());
                    for (int v_i{}; v_i < usr_dn.size(); ++v_i) {
                        cout << usr_dn[v_i] << " ";
                    }
                    cout << endl;
                    usr_dn.clear();
                }

            } else {
                // or
                string exp1, exp2;
                bool start{false};
                int flag{}, flag1{}, flag2{};
                char op1, op2;
                for (int j{}; j < exp.length(); ++j) {
                    if (start) {
                        exp1 += exp[j];
                    }
                    if (exp[j] == '(') {
                        start = true;
                    } else if (exp[j] == ')') {
                        start = false;
                        flag = j + 1;
                        break;
                    }
                }
                for (int j{flag}; j < exp.length(); ++j) {
                    if (start) {
                        exp2 += exp[j];
                    }
                    if (exp[j] == '(') {
                        start = true;
                    } else if (exp[j] == ')') {
                        start = false;
                        break;
                    }
                }
                bool condition1{false}, condition2{false};
                string attr_s1, value_s1, attr_s2, value_s2;
                // atomic expression
                // exp1
                for (int j{}; j < exp1.length(); ++j) {
                    if (exp1[j] >= '0' and exp1[j] <= '9') {
                        attr_s1 += exp1[j];
                    } else {
                        flag1 = j + 1;
                        op1 = exp1[j];
                        break;
                    }
                }
                // clog << "CLOG: OP1# " << op1 << endl;
                for (int j{flag1}; j < exp1.length(); ++j) {
                    if (exp1[j] >= '0' and exp1[j] <= '9') {
                        value_s1 += exp1[j];
                    }
                }

                int attr_i1{stoi(attr_s1)};
                int value_i1{stoi(value_s1)};
                // clog << "CLOG: 1# " << attr_i1 << " " << value_i1 << endl;

                // exp2
                for (int j{}; j < exp2.length(); ++j) {
                    if (exp2[j] >= '0' and exp2[j] <= '9') {
                        attr_s2 += exp2[j];
                    } else {
                        flag2 = j + 1;
                        op2 = exp2[j];
                        break;
                    }
                }
                // clog << "CLOG: OP2# " << op2 << endl;
                for (int j{flag2}; j < exp2.length(); ++j) {
                    if (exp2[j] >= '0' and exp2[j] <= '9') {
                        value_s2 += exp2[j];
                    }
                }

                int attr_i2{stoi(attr_s2)};
                int value_i2{stoi(value_s2)};
                // clog << "CLOG: 2# " << attr_i2 << " " << value_i2 << endl;

                if (op1 == ':' and op2 == ':') {
                    // ::
                    bool condition1{false}, condition2{false};
                    for (int k{}; k < n; ++k) {
                        for (int l{}; l < 501; ++l) {
                            if (usr[k].usr_att[l].attribute == attr_i1 and
                                usr[k].usr_att[l].value == value_i1) {
                                condition1 = true;
                            }
                            if (usr[k].usr_att[l].attribute == attr_i2 and
                                usr[k].usr_att[l].value == value_i2) {
                                condition2 = true;
                            }
                            if (condition1 or condition2) {
                                // cout << usr[k].dn << " ";
                                usr_dn.push_back(usr[k].dn);
                                condition1 = false;
                                condition2 = false;
                                break;
                            }
                        }
                    }
                    sort(usr_dn.begin(), usr_dn.end());
                    for (int v_i{}; v_i < usr_dn.size(); ++v_i) {
                        cout << usr_dn[v_i] << " ";
                    }
                    cout << endl;
                    usr_dn.clear();
                } else if (op1 == ':' and op2 == '~') {
                    // :~
                    bool condition1{false}, condition2{false};
                    for (int k{}; k < n; ++k) {
                        for (int l{}; l < 501; ++l) {
                            if (usr[k].usr_att[l].attribute == attr_i1 and
                                usr[k].usr_att[l].value == value_i1) {
                                condition1 = true;
                            }
                            if (usr[k].usr_att[l].attribute == attr_i2 and
                                usr[k].usr_att[l].value != value_i2) {
                                condition2 = true;
                            }
                            if (condition1 or condition2) {
                                // cout << usr[k].dn << " ";
                                usr_dn.push_back(usr[k].dn);
                                condition1 = false;
                                condition2 = false;
                                break;
                            }
                        }
                    }
                    sort(usr_dn.begin(), usr_dn.end());
                    for (int v_i{}; v_i < usr_dn.size(); ++v_i) {
                        cout << usr_dn[v_i] << " ";
                    }
                    cout << endl;
                    usr_dn.clear();
                } else if (op1 == '~' and op2 == ':') {
                    // ~:
                    bool condition1{false}, condition2{false};
                    for (int k{}; k < n; ++k) {
                        for (int l{}; l < 501; ++l) {
                            if (usr[k].usr_att[l].attribute == attr_i1 and
                                usr[k].usr_att[l].value != value_i1) {
                                condition1 = true;
                            }
                            if (usr[k].usr_att[l].attribute == attr_i2 and
                                usr[k].usr_att[l].value == value_i2) {
                                condition2 = true;
                            }
                            if (condition1 or condition2) {
                                // cout << usr[k].dn << " ";
                                usr_dn.push_back(usr[k].dn);
                                condition1 = false;
                                condition2 = false;
                                break;
                            }
                        }
                    }
                    sort(usr_dn.begin(), usr_dn.end());
                    for (int v_i{}; v_i < usr_dn.size(); ++v_i) {
                        cout << usr_dn[v_i] << " ";
                    }
                    cout << endl;
                    usr_dn.clear();
                } else if (op1 == '~' and op2 == '~') {
                    // ~~
                    bool condition1{false}, condition2{false};
                    for (int k{}; k < n; ++k) {
                        for (int l{}; l < 501; ++l) {
                            if (usr[k].usr_att[l].attribute == attr_i1 and
                                usr[k].usr_att[l].value != value_i1) {
                                condition1 = true;
                            }
                            if (usr[k].usr_att[l].attribute == attr_i2 and
                                usr[k].usr_att[l].value != value_i2) {
                                condition2 = true;
                            }
                            if (condition1 or condition2) {
                                cout << usr[k].dn << " ";
                                condition1 = false;
                                condition2 = false;
                                break;
                            }
                        }
                    }
                    sort(usr_dn.begin(), usr_dn.end());
                    for (int v_i{}; v_i < usr_dn.size(); ++v_i) {
                        cout << usr_dn[v_i] << " ";
                    }
                    cout << endl;
                    usr_dn.clear();
                }
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
                            // cout << usr[k].dn << " ";
                            usr_dn.push_back(usr[k].dn);
                            break;
                        }
                    }
                }
                sort(usr_dn.begin(), usr_dn.end());
                for (int v_i{}; v_i < usr_dn.size(); ++v_i) {
                    cout << usr_dn[v_i] << " ";
                }
                cout << endl;
                usr_dn.clear();
            } else {
                // find dn, not equal
                for (int k{}; k < n; ++k) {
                    for (int l{}; l < 501; ++l) {
                        if (usr[k].usr_att[l].attribute == attr_i and
                            usr[k].usr_att[l].value != value_i) {
                            // cout << usr[k].dn << " ";
                            usr_dn.push_back(usr[k].dn);
                            break;
                        }
                    }
                }
                sort(usr_dn.begin(), usr_dn.end());
                for (int v_i{}; v_i < usr_dn.size(); ++v_i) {
                    cout << usr_dn[v_i] << " ";
                }
                cout << endl;
                usr_dn.clear();
            }
        }
    }
    return 0;
}
