// ccf-csp 201403-5

#include <iostream>

using namespace std;

/*
 * 有两个 CPU 和一个 GPU
 * 1. 在一个 CPU 上面运行
 * 2. 在两个 CPU 上面运行
 * 3. 在一个 CPU 和一个 GPU 上面运行
 * 4. 在两个 CPU 和一个 GPU 上面运行
 */

const int N{43}, M{403};
int n, a[N][6], ans{(int) 1e9}, f[M][M][M];
int p[5][3]{
        {2, 2, 2},
        {0, 1, 0},
        {1, 0, 0},
        {0, 3, 3},
        {3, 0, 3}
};

struct Node {
    int nc, nx, ny, nz;

    explicit Node(
            int nc = 0,
            int nx = 0,
            int ny = 0,
            int nz = 0
    ) : nc(nc), nx(nx), ny(ny), nz(nz) {};
};

Node q[(int) 7e4];

void work() {
    int current, x, y, z, now;
    int t{};
    t++;
    q[t] = Node(0, 0, 0, 0);
    f[0][0][0] = -1;
    while (t > 0) {
        Node &ht{q[t]};
        t--;
        current = ht.nc;
        x = ht.nx;
        y = ht.ny;
        z = ht.nz;
        if (f[x][y][z] >= current) {
            continue;
        }
        f[x][y][z] = current;
        now = max(x, max(y, z));
        if (now > ans) {
            continue;
        }
        if ((++current) == n + 1) {
            ans = min(ans, now);
            continue;
        }
        for (int i{}; i < 5; ++i) {
            t++;
            q[t] = Node(
                    current,
                    x + a[current][p[i][0]],
                    y + a[current][p[i][1]],
                    z + a[current][p[i][2]]
            );
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= 4; ++j) {
            cin >> a[i][j];
        }
    }
    work();
    return 0;
}
