// ccf-csp 202206-4

#include <iostream>
#include <vector>

using namespace std;

struct Reflect_surface {
    int x1, y1, x2, y2;  // 反射面的坐标起始点和终止点
    double a;  // 反射系数
    int surface_number;  // 插入反射面编号
};

int main() {
    ios::sync_with_stdio(false);
    int m{};
    cin >> m;
    vector<Reflect_surface> sur;
    vector<Reflect_surface>::iterator it;
    int temp_num{};
    while (m--) {
        int operation_number{};
        cin >> operation_number;
        if (operation_number == 1) {
            // 添加一个反射面
            int temp_x1{}, temp_y1{}, temp_x2{}, temp_y2{};
            double temp_a{};
            cin >> temp_x1 >> temp_y1 >> temp_x2 >> temp_y2 >> temp_a;
            Reflect_surface tmp_r_s{
                    temp_x1,
                    temp_y1,
                    temp_x2,
                    temp_y2,
                    temp_a,
                    temp_num
            };
            temp_num++;
            sur.push_back(tmp_r_s);
        } else if (operation_number == 2) {
            // 删除反射面
            int k{};
            cin >> k;
            while (!sur.empty()) {
                int i{};
                for (it = sur.begin(); it != sur.end(); ++it) {
                    i++;
                    if (sur.at(i).surface_number == k) {
                        sur.erase(it);
                        break;
                    }
                }
            }
        } else if (operation_number == 3) {
            // 添加一个光源
            int glow_x{}, glow_y{}, glow_d{}, glow_i{}, glow_t{};
            cin >> glow_x >> glow_y >> glow_d >> glow_i >> glow_t;
        }
    }
    return 0;
}
