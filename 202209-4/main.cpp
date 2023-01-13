// ccf csp 202209-4

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{}, m{}, q{};
    cin >> n >> m >> q;  // 輸入投票者人數 n，作品數 m，拉票事件數 q
    int *a{new int[n + 1]};  // 每個投票者嘅投票意願
    for (int i{}; i < n + 1; ++i) {
        a[i] = 0;  // 初始化
    }
    int *artworks{new int[m + 1]};  // 每個作品收到嘅投票
    for (int i{}; i < m + 1; ++i) {
        artworks[i] = 0;  // 初始化
    }
    while (q--) {
        int number{};  // 數字表示係咩事件
        cin >> number;  // 輸入數字表示事件
        if (number == 1) {
            // 編號為 x 嘅作品開展咗一個拉票活動
            int l{}, r{}, x{};
            cin >> l >> r >> x;
            // 從 l 到 r 編號嘅投票者意願全部變成 x
            for (int i{l}; i <= r; ++i) {
                a[i] = x;
            }
        } else if (number == 2) {
            // 意願為 x 嘅投票者變成意願為 w
            int x{}, w{};
            cin >> x >> w;
            // 尋找意願為 x 嘅投票者
            for (int i{1}; i < n + 1; ++i) {
                if (a[i] == x) {
                    a[i] = w;  // 意願改為 w
                }
            }
        } else if (number == 3) {
            // x 嘅意願同 y 嘅意願對調
            int x{}, y{};
            cin >> x >> y;
            for (int i{1}; i < n + 1; ++i) {
                if (a[i] == x) {
                    a[i] = -1;
                }
            }
            for (int i{1}; i < n + 1; ++i) {
                if (a[i] == y) {
                    a[i] = x;
                }
            }
            for (int i{1}; i < n + 1; ++i) {
                if (a[i] == -1) {
                    a[i] = y;
                }
            }
        } else if (number == 4) {
            // 調查投票意願為 w 嘅有多少人
            int w{};
            cin >> w;
            int counter{};  // 統計投票意願為 w 嘅人數
            for (int i{1}; i < n + 1; ++i) {
                if (a[i] == w) {
                    counter++;  // 如果係，就加一
                }
            }
            cout << counter << endl;  // 輸出調查結果
        } else if (number == 5) {
            // 投出獲勝作品
            // 統計票數
            for (int i{1}; i < n + 1; ++i) {
                artworks[a[i]]++;
            }
            int winner{};  // 獲勝作品號
            int max_vote{};  // 最高票數
            for (int i{1}; i < m + 1; ++i) {
                if (artworks[i] > max_vote) {
                    max_vote = artworks[i];
                    winner = i;
                }
            }
            cout << winner << endl;
            for (int i{}; i < m + 1; ++i) {
                artworks[i] = 0;  // 統計清零
            }
        }
    }
    delete[] a;
    delete[] artworks;
    return 0;
}
