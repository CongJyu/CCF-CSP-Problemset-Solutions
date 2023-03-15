// ccf-csp 202206-3

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

// 把用户和用户组都看成用户

// 存放角色属性的结构体
struct J {
    set<string> opt;  // 操作
    set<string> resource_name;  // 资源名称
    set<string> resource_type;  // 资源类型
};

map<string, J> character;  // 角色名
typedef set<string> connect;  // 角色库，存放每个用户、用户组所关联的角色
map<string, connect> user;  // 用户名关联的角色库

int n, m, q;
int nv, no, nn, ns, ng;
string q_name, q_resource_type, q_resource_name;  // 输入的待查询的名称、资源种类和资源名称

bool judge(const string &name) {
    connect character_lib{user[name]};
    for (auto it{character_lib.begin()}; it != character_lib.end(); ++it) {
        const string &character_name{*it};
        if (character[character_name].opt.count(q_name) or character[character_name].resource_type.count("*")) {
            if (character[character_name].resource_type.count(q_resource_type) or
                character[character_name].resource_type.count("*")) {
                if (character[character_name].resource_name.count(q_resource_name) or
                    character[character_name].resource_name.empty()) {
                    return true;  // 找到一个关联的角色可以完成操作
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i{}; i < n; ++i) {
        string name, st;
        cin >> name;
        cin >> nv;
        while ((nv--) > 0) {
            cin >> st;
            character[name].opt.insert(st);
        }
    }
    for (int i{}; i < q; ++i) {
        string name, uname;
        cin >> name;
        cin >> ns;
        while ((ns--) > 0) {
            cin >> uname;
            cin >> uname;  // 用户名
            user[uname].insert(name);
        }
    }
    for (int i{}; i < q; ++i) {
        bool fg{false};
        queue<string> ls;  // 用户名列表
        string name;
        cin >> name >> ng;
        ls.push(name);
        while ((ng--) > 0) {
            cin >> name;
            ls.push(name);
        }
        // 存列表，逐个判断能否完成操作
        cin >> q_name >> q_resource_type >> q_resource_name;
        while (!ls.empty()) {
            if (judge(ls.front())) {
                fg = true;
                cout << 1 << endl;
                break;
            }
            ls.pop();
        }
        if (!fg) {
            cout << 0 << endl;
        }
    }
    return 0;
}
