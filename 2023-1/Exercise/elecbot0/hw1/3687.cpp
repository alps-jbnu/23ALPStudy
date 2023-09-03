#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int min_num[8] = { 0, 0, 1, 7, 4, 2, 0, 8 };
    long long min_dp[101];
    fill(min_dp, min_dp + 101, LONG_LONG_MAX);
    min_dp[1] = 9; min_dp[2] = 1; min_dp[3] = 7;
    min_dp[4] = 4; min_dp[5] = 2; min_dp[6] = 6; min_dp[7] = 8;
    for (int i = 8; i <= 100; i++) {
        for (int j = 2; j <= 7; j++) {
            min_dp[i] = min(min_dp[i], min_dp[i - j] * 10 + min_num[j]);
        }
    }
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << min_dp[N] << " ";
        vector<char> max_v;
        while (N > 0) {
            if (N == 3) {
                max_v.emplace_back('7');
                N -= 3;
            } else {
                max_v.emplace_back('1');
                N -= 2;
            }
        }
        for (auto it = max_v.rbegin(); it != max_v.rend(); it++) {
            cout << *it;
        }
        cout << "\n";
    }
    return 0;
}
