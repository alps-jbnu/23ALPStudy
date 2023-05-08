#include <bits/stdc++.h>

using namespace std;

int N, car;
int people_sum[50001];
int memo[4][50001];

int answer(int cur_i, int cur_car) {
    if (cur_car == 3) return 0;
    if (cur_i > N) return 0;
    if (memo[cur_car][cur_i] != -1) return memo[cur_car][cur_i];
    int ans = answer(cur_i + car, cur_car + 1);
    ans += people_sum[min(N, cur_i + car)] - people_sum[cur_i];
    ans = max(ans, answer(cur_i + 1, cur_car));
    return memo[cur_car][cur_i] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int num; cin >> num;
        people_sum[i] = people_sum[i - 1] + num;
    }
    cin >> car;
    for (int i = 0; i < 4; i++) {
        fill(memo[i], memo[i] + 50001, -1);
    }
    cout << answer(0, 0);
    return 0;
}
