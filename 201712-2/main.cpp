// ccf-csp 201712-2

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n{}, k{};
    cin >> n >> k;
    queue<int> ring;
    int call_number{1};
    for (int i{1}; i <= n; ++i) {
        ring.push(i);
    }
    while (ring.size() != 1) {
        if (call_number % k == 0 or to_string(call_number)[(int) to_string(call_number).size() - 1] == k + '0') {
            ring.pop();
            call_number++;
        } else {
            ring.push(ring.front());
            ring.pop();
            call_number++;
        }
    }
    cout << ring.front() << endl;
    return 0;
}
