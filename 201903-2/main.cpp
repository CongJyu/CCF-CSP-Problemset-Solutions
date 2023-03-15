// ccf-csp 201903-2

#include <iostream>
#include <stack>

using namespace std;

void solution() {
    string exp;
    cin >> exp;
    stack<int> num;
    int result{1};
    for (int i{}; i < (int) exp.length(); ++i) {
        if (exp[i] >= '0' and exp[i] <= '9') {
            num.push(result * (exp[i] - '0'));
        } else if (exp[i] == '+') {
            result = 1;
        } else if (exp[i] == '-') {
            result = -1;
        } else {
            int a{num.top()};
            num.pop();
            i++;
            int b{exp[i] - '0'};
            if (exp[i - 1] == 'x') {
                num.push(a * b);
            } else {
                num.push(a / b);
            }
        }
    }
    int out{};
    while (!num.empty()) {
        out += num.top();
        num.pop();
    }
    if (out == 24) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;
    while (n--) {
        solution();
    }
    return 0;
}
