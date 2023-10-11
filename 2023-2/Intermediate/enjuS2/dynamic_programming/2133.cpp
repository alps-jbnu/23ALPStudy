#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int dp[40];
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    if (n % 2 == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * dp[2];
        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] = dp[i] + (dp[j] * 2);
        }
    }

    cout << dp[n];
    return 0;
}
