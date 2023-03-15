// ccf-csp 201509-2

#include <iostream>

using namespace std;

int day[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_run(int year) {
    if ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int y{}, d{};
    cin >> y >> d;
    if (is_run(y)) {
        // 是闰年
        day[1] = 29;
        int month{1}, total{};
        while (total < d) {
            total += day[month - 1];
            month++;
            if (total > d) {
                month--;
                total -= day[month - 1];
                break;
            }
        }
        cout << month << endl << d - total << endl;
    } else {
        // 不是闰年
        day[1] = 28;
        int month{1}, total{};
        while (total < d) {
            total += day[month - 1];
            month++;
            if (total > d) {
                month--;
                total -= day[month - 1];
                break;
            }
        }
        cout << month << endl << d - total << endl;
    }
    return 0;
}
