// ccf-csp 201703-3

#include <iostream>
#include <string>

using namespace std;

string str;
string temp;  // 输出缓存
int block_status{};  // 1 段落 2 标题 3 无序列表 0 就绪下一个区块

string handle_em(string ss) {
    return "<em>" + ss.substr(1, ss.size() - 2) + "</em>";
}

string handle_a(string ss) {
    int pos{};
    for (int i{1}; i < (int) ss.size(); ++i) {
        if (ss[i] == ']') {
            pos = i;
            break;
        }
    }
    return "<a href=\"" + ss.substr(pos + 2, ss.size() - (pos + 2) - 1)
           + "\">" + ss.substr(1, pos - 1) + "</a>";
}

string handle_line(string ss) {
    string r1, r2;
    for (int i{}; i < (int) ss.size();) {
        if (ss[i] == '_') {
            int pos{};
            for (int j{i + 1}; j < (int) ss.size(); ++j) {
                if (ss[j] == '_') {
                    pos = j;
                    break;
                }
            }
            r1 += handle_em(ss.substr(i, pos - i + 1));
            i = pos + 1;
        } else {
            r1.push_back(ss[i]);
            i++;
        }
    }
    for (int i{}; i < (int) r1.size();) {
        
    }
}

int main() {
    ios::sync_with_stdio(false);

    return 0;
}
