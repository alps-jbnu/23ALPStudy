#include <bits/stdc++.h>

using namespace std;

bool che[500001];
int N, cnt, zero_cnt;
vector<long long> price;
int price_cnt[10001];
long long dp[500001];

long long answer() {
    dp[0] = 1;
    int maxi = 0;
    for (int i = 0; i < cnt; i++) {
        for (int j = maxi; j >= 0; j--) {
            for (int k = 1; k <= price_cnt[price[i]]; k++) {
                if (j + k * price[i] >= 500000) break;
                dp[j + k * price[i]] += dp[j];
            }
        }
        maxi += price[i] * price_cnt[price[i]];
        maxi = min(maxi, 500000);
    }
    long long ans = 0;
    for (int i = 2; i <= 500000; i++) {
        if (!che[i]) ans += dp[i];
    }
    ans *= zero_cnt;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    che[0] = che[1] = true;
    for (int i = 2; i <= 500000; i++) {
        if (che[i]) continue;
        for (int j = i + i; j <= 500000; j += i) {
            che[j] = true;
        }
    }
    cin >> N;
    zero_cnt = 1;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        if (!num) {
            zero_cnt += 1;
            continue;
        }
        if (!price_cnt[num]) {
            price.emplace_back(num);
        }
        price_cnt[num]++;
    }
    cnt = price.size();
    cout << answer();
    return 0;
}
