#include <bits/stdc++.h>

using namespace std;

int preix_sum[1001][1001];
int board[1001][1001];
bool vis[1001][1001];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
            preix_sum[i][j] = preix_sum[i-1][j] + preix_sum[i][j-1] - preix_sum[i-1][j-1] + board[i][j];
        }
    }
    int H, W, Sr, Sc, Fr, Fc; cin >> H >> W >> Sr >> Sc >> Fr >> Fc;
    queue<pair<int,int>> q;
    q.push(make_pair(Sr, Sc));
    vis[Sr][Sc] = true;
    int answer = 0;
    while(!q.empty())
    {
        int qs = q.size();
        while(qs--)
        {
            auto cur = q.front(); q.pop();
            if(cur.first == Fr && cur.second == Fc)
            {
                cout << answer;
                return 0;
            }
            for(int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 1 || ny < 1 || nx > N || ny > M || nx + H - 1< 1 || ny + W - 1 < 1 || nx + H - 1 > N || ny + W - 1 > M) continue;
                if(vis[nx][ny]) continue;
                if(preix_sum[nx + H - 1][ny + W - 1] - preix_sum[nx + H - 1][ny - 1] - preix_sum[nx - 1][ny + W -1] + preix_sum[nx - 1][ny - 1] > 0) continue;
                q.push(make_pair(nx, ny));
                vis[nx][ny] = true;
            }
        }
        answer++;
    }
    cout << -1;
    return 0;
}
