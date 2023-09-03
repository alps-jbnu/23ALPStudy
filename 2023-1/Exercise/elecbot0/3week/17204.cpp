#include <bits/stdc++.h>

using namespace std;

int N, K;
int target[150];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> target[i];
    int cur_i = 0;
    int cur_num = 1;
    int answer = -1;
    while (cur_i != K && cur_num < 150) {
        cur_i = target[cur_i];
        if (cur_i == K) {
            answer = cur_num;
        }
        cur_num += 1;
    }
    cout << answer;
    return 0;
}
