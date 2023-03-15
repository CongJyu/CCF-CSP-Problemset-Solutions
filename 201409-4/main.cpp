// ccf-csp 201409-4

#include <iostream>
#include <queue>

using namespace std;

int n{}, m{}, k{}, d{};
int sum{};
long long ans{};
bool visited[1001][1001]{false};
int food[1001][1001]{};

struct Node {
    int x, y, step;

    Node() {}

    Node(int xx, int yy, int stepp) {
        x = xx;
        y = yy;
        step = stepp;
    }
};

queue<Node> q;

struct Orient {
    int x, y;
};

Orient ori[4]{
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
};

long long bfs(int N) {
    Node a, b;
    while (!q.empty()) {
        a = q.front();
        q.pop();
        for (int i{}; i <= 3; ++i) {
            b.x = a.x + ori[i].x;
            b.y = a.y + ori[i].y;
            b.step = a.step + 1;
            if (b.x < 1 or b.x > N or b.y < 1 or b.y > N or visited[b.x][b.y]) {
                continue;
            }
            if (food[b.x][b.y] > 0) {
                ans += food[b.x][b.y] * b.step;
                sum--;
                if (sum == 0) {
                    return ans;
                }
                visited[b.x][b.y] = true;
                q.push(b);
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int x{}, y{}, z{};
    cin >> n >> m >> k >> d;
    while (m--) {
        cin >> x >> y;
        visited[x][y] = true;
        q.push(Node(x, y, 0));
    }
    while (k--) {
        cin >> x >> y >> z;
        if (food[x][y] == 0) {
            sum++;
        }
        food[x][y] += z;
    }
    while (d--) {
        cin >> x >> y;
        visited[x][y] = true;
    }
    bfs(n);
    cout << ans << endl;
    return 0;
}
