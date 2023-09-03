#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> orders;
int dp[101][301][301];
int N, M, K;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    orders.push_back(make_pair(0,0));
    for(int i = 0; i < N; i++)
    {
        int x,y; cin >> x >> y;
        orders.push_back(make_pair(x, y));
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            for(int k = 1; k <= K; k++)
            {
                if(j >= orders[i].first && k >= orders[i].second)
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - orders[i].first][k - orders[i].second] + 1);
                else
                    dp[i][j][k] = dp[i - 1][j][k];
            }
        }
    }
    cout << dp[N][M][K];
    return 0;
}
