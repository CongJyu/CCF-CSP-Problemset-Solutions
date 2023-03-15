// ccf-csp 201803-1

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int block{}, score{}, accumulate_adding_score{2};
    int last_block{};
    while (true) {
        cin >> block;
        if (block == 0) {
            break;
        }
        if (block == 1) {
            accumulate_adding_score = 2;
            score++;
            last_block = block;
        } else if (block == 2) {
            if (last_block == 2) {
                accumulate_adding_score += 2;
            }
            score += accumulate_adding_score;
            last_block = block;
        }
    }
    cout << score << endl;
    return 0;
}
