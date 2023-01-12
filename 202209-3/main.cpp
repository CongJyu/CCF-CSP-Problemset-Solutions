// ccf csp 202209-3

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Data {
    int day;  // 日期
    int user;  // 用戶
    int region;  // 地區
};
vector<Data> roaming_data;  // 漫遊消息
map<int, pair<int, int> > region_risk_last_time;  // 每個地區嘅風險持續時間
map<int, bool> is_risk_region;  // 每個地區是否被設為風險區

void set_risk_region(int this_region, int this_day) {
    // 將 this_region 設定為 this_day 風險區
    if (!is_risk_region.at(this_region)) {
        region_risk_last_time.at(this_region) = {this_day, this_day + 6};
    } else {
        if (this_day <= region_risk_last_time.at(this_region).second + 1) {
            region_risk_last_time.at(this_region).second = this_day + 6;  // 可以連起來
        } else {
            region_risk_last_time.at(this_region) = {this_day, this_day + 6};
        }
    }
    is_risk_region.at(this_region) = true;
}

bool check_roaming_messages(int roaming_day, int roaming_user, int roaming_region, int current_day) {
    // 檢查漫遊消息是否滿足
    if (is_risk_region.at(roaming_region) and current_day >= roaming_day - 6
        and current_day >= region_risk_last_time.at(roaming_region).first
        and roaming_day <= region_risk_last_time.at(roaming_region).second) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;  // 輸入天數
    int ri{}, mi{};  // 地區數目 and 訊息數目
    for (int i{}; i < n; ++i) {
        cin >> ri >> mi;
        for (int j{}; j < ri; ++j) {
        }
    }
    return 0;
}
