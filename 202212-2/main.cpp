// ccf csp 202212-2

#include <iostream>

using namespace std;

struct Course {
    int form = 0;
    int day = 0;
    int start = 1;
    int last_start = 0;
} course[101];

int main() {
    ios::sync_with_stdio(false);
    int max_v{-1};
    int n{}, m{};
    cin >> n >> m;
    for (int i{}; i < m; ++i) {
        cin >> course[i].form;
    }
    for (int i{}; i < m; ++i) {
        cin >> course[i].day;
    }
    for (int i{}; i < m; ++i) {
        if (course[i].form != 0) {
            course[i].start = course[course[i].form - 1].start + course[course[i].form - 1].day;
        }
        cout << course[i].start << " ";
        if (course[i].day + course[i].start > max_v) {
            max_v = course[i].day + course[i].start - 1;
        }
    }
    if (max_v <= n) {
        cout << endl;
        for (int i{m - 1}; i >= 0; --i) {
            if (course[i].last_start == 0) {
                course[i].last_start = n - course[i].day + 1;
            }
            if (course[i].form != 0) {
                int tmp{course[i].last_start - course[course[i].form - 1].day};
                if (course[course[i].form - 1].last_start == 0) {
                    course[course[i].form - 1].last_start = tmp;
                } else {
                    course[course[i].form - 1].last_start = min(tmp, course[course[i].form - 1].last_start);
                }
            }
        }
        for (int i{}; i < m; ++i) {
            cout << course[i].last_start << " ";
        }
    }
    return 0;
}
