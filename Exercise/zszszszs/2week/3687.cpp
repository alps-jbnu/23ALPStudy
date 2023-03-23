#include <bits/stdc++.h>
using namespace std;

long long dp[105];

int main(void)
{
    ios_base::sync_with_stdio(0);
    int min_num[8] = {0, 0, 1, 7, 4, 2, 0, 8};
    int n;
    cin >> n;

    dp[1] = 9;
    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;
    fill(dp + 8, dp + 101, 0x7ffffffffffff);
    for (int i = 8; i <= 100; ++i)
        for (int j = 2; j <= 7; ++j)
            dp[i] = min(dp[i], dp[i - j] * 10 + min_num[j]);

    for (int i = 0; i < n; i++)
    {
        string ans2;
        long long a;
        cin >> a;

        if (a % 2 == 0)
        {

            for (int j = 0; j < a / 2; j++)
            {

                ans2 += '1';
            }
        }
        if (a % 2 != 0)
        {
            ans2 += '7';
            for (int j = 0; j < (a - 3) / 2; j++)
            {
                ans2 += '1';
            }
        }
        cout << dp[a] << ' ';
        cout << ans2 << '\n';
    }
}