// ccf csp 202209-3

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 漫遊消息
struct Data {
    int day;  // 日期
    int user;  // 用戶
    int region;  // 地區
};
vector<Data> roaming_data[1000];  // 漫遊消息
map<int, pair<int, int> > region_risk_last_time;  // 每個地區嘅風險持續時間
map<int, bool> is_risk_region;  // 每個地區是否被設為風險區

// 將 this_region 設定為 this_day 風險區
void set_risk_region(int this_region, int this_day) {
    if (!is_risk_region[this_region]) {
        region_risk_last_time[this_region] = {this_day, this_day + 6};
    } else {
        if (this_day <= region_risk_last_time[this_region].second + 1) {
            region_risk_last_time[this_region].second = this_day + 6;  // 可以連起來
        } else {
            region_risk_last_time[this_region] = {this_day, this_day + 6};
        }
    }
    is_risk_region[this_region] = true;
}

// 檢查漫遊消息是否滿足
bool check_roaming_messages(int roaming_day, int roaming_user, int roaming_region, int current_day) {
    if (is_risk_region[roaming_region] and roaming_day >= current_day - 6 and roaming_day <= current_day and
        roaming_day >= region_risk_last_time[roaming_region].first and
        current_day <= region_risk_last_time[roaming_region].second) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n{};
    cin >> n;  // 輸入天數
    int r{}, m{};  // 風險地區訊息數量 and 當日收到數據條目數量
    for (int i{}; i < n; ++i) {
        // i 表示當前日期
        cin >> r >> m;
        // 讀入風險區並更新
        for (int j{1}; j <= r; ++j) {
            int p{};
            cin >> p;  // 讀入地區列表
            set_risk_region(p, i);
        }
        // 讀入漫遊消息並存入
        for (int j{1}; j <= m; ++j) {
            Data roaming_msg{};
            cin >> roaming_msg.day >> roaming_msg.user >> roaming_msg.region;
            // int msg_day{}, msg_user{}, msg_region{};
            // cin >> msg_day >> msg_user >> msg_region;
            if (roaming_msg.day <= i) {
                // 如果天數小於當前天數，推入漫遊數據 vector 中
                roaming_data[i].push_back(roaming_msg);
            }
        }
        vector<int> current_risk_list;  // 當日嘅風險名單
        if (!current_risk_list.empty()) {
            current_risk_list.clear();
        }
        // 遍歷漫遊消息，滿足條件嘅加入當日風險名單中
        for (int j{i - 6 >= 0 ? i - 6 : 0}; j <= i; ++j) {
            for (int k{}; k < roaming_data[j].size(); ++k) {
                if (check_roaming_messages(roaming_data[j][k].day, roaming_data[j][k].user, roaming_data[j][k].region,
                                           i)) {
                    current_risk_list.push_back(roaming_data[j][k].user);
                }
            }
        }
        // 從小到大排列
        sort(current_risk_list.begin(), current_risk_list.end());
        // 去除重複嘅數據
        current_risk_list.erase(unique(current_risk_list.begin(), current_risk_list.end()), current_risk_list.end());
        cout << i;  // 輸出當日嘅日期
        for (int j{}; j < current_risk_list.size(); ++j) {
            cout << " " << current_risk_list[j];
        }
        cout << endl;
    }
    return 0;
}
