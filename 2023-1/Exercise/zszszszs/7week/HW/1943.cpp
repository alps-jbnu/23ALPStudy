#include <bits/stdc++.h>
using namespace std;

pair<int, int> coin[101];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    for (int i = 0; i < 3; i++)
    {
        bool dp[100005];
        cin >> n;
        int money = 0;
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            money += a * b;
            coin[j] = {a, b};
        }
        if (money % 2 == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        money /= 2;
        sort(coin, coin + n);

        for (int j = 0; j < n; j++)
        {
            for (int k = money; k >= coin[j].first; k--)
            {
                if (dp[k - coin[j].first])
                {

                    for (int p = 0; p < coin[j].second; p++)
                    {
                        if (k + p * coin[i].first > money)
                            break;
                        dp[k + p * coin[j].first] = true;
                    }
                }
            }
        }

        if (dp[money])
            cout << 1 << '\n';

        else
            cout << 0 << '\n';
    }
}