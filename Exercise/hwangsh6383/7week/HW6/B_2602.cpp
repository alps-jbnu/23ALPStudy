#include <bits/stdc++.h>

using namespace std;

int dp[21][2][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string st, devil, angel; cin >> st >> devil >> angel;
    for(int i = 0; i < devil.length(); i++)
    {
        if(devil[i] == st[0])
        {
            dp[0][0][i] = 1;
        }
        if(angel[i] == st[0])
        {
            dp[0][1][i] = 1;
        }
    }

    for(int i = 1; i < st.length(); i++)
    {
        for(int k = 0; k < devil.length(); k++)
        {
            int cnt = 0;
            if(devil[k] == st[i])
            {
                for(int m = 0; m < k; m++)
                {
                    cnt += dp[i - 1][1][m];
                }
                dp[i][0][k] = cnt;
            }
            cnt = 0;
            if(angel[k] == st[i])
            {
                for(int m = 0; m < k; m++)
                {
                    cnt += dp[i - 1][0][m];
                }
                dp[i][1][k] = cnt;
            }
        }
    }
    int answer = 0;
    for(int k = 0; k < devil.length(); k++)
    {
        answer += dp[st.length() - 1][0][k];
        answer += dp[st.length() - 1][1][k];
    }
    cout << answer;
    return 0;
}
