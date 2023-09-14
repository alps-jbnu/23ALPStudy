#include <bits/stdc++.h>

using namespace std;

int n;
int ps[50005];
int dp[4][50005];
int k;

int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        ps[i] = ps[i - 1] + tmp;
    }
    cin >> k;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = i * k; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + ps[j] - ps[j - k]);
        }
    }
    cout << dp[3][n];
}