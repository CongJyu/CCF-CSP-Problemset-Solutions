// ccf-csp 201403-4

#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

const int maxm{100}, maxn{100};
int n{}, m{}, k{};
double r{};

struct T_Node {
    double x, y;
    int type;
};

T_Node node[maxn + maxm + 10];

int to[(maxn + maxm) * (maxn + maxm) * 2 + 10];
int nex[(maxn + maxm) * (maxn + maxm) * 2 + 10];
int head[maxn + maxm + 10], cnt = 0;

void add_edge(int x, int y) {
    to[cnt] = y;
    nex[cnt] = head[x];
    head[x] = cnt++;
    to[cnt] = x;
    nex[cnt] = head[y];
    head[y] = cnt++;
}

int vis[maxn + maxm + 10][maxm + 10];

struct T_NNode {
    int a, b, dis;

    T_NNode(int aa, int bb, int ddis) : a(aa), b(bb), dis(ddis) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> r;
    for (int i{1}; i <= n + m; ++i) {
        cin >> node[i].x >> node[i].y;
        node[i].type = (i <= n) ? 0 : 1;
    }
    memset(head, -1, sizeof(head));
    for (int i{1}; i <= n + m; ++i) {
        for (int j{i + 1}; j <= n + m; ++j) {
            double dist{sqrt(pow((node[i].x - node[j].x), 2.0) + pow((node[i].y - node[j].y), 2.0))};
            if (dist <= r) {
                add_edge(i, j);
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    queue<T_NNode> q;
    q.push(T_NNode(1, 0, 0));
    vis[1][0] = 1;
    while (true) {
        T_NNode x{q.front()};
        q.pop();
        int a{x.a}, b{x.b}, dis{x.dis};
        if (a == 2) {
            cout << dis - 1 << endl;
            break;
        }
        for (int i{head[a]}; i != -1; i = nex[i]) {
            int l{to[i]};
            if (node[l].type == 0) {
                if (!vis[l][b]) {
                    q.push(T_NNode(l, b, dis + 1));
                    vis[l][b] = 1;
                }
            } else {
                if (b < k and !vis[l][b + 1]) {
                    q.push(T_NNode(l, b + 1, dis + 1));
                    vis[l][b + 1] = 1;
                }
            }
        }
    }
    return 0;
}
