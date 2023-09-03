#include <bits/stdc++.h>

using namespace std;

bool road[101][101][101][101];
int loc[101][101];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, R; cin >> N >> K >> R;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            loc[i][j] = 101;
        }
    }
    for(int i = 0; i < R; i++)
    {
        int r, c, rr, cc; cin >> r >> c >> rr >> cc;
        road[r][c][rr][cc] = true;
        road[rr][cc][r][c] = true;
    }
    vector<pair<int,int>> cows;
    for(int i = 1; i <= K; i++)
    {
        int x, y; cin >> x >> y;
        cows.push_back(make_pair(x, y));
        loc[x][y] = i;
    }
    int j = 1;
    for(auto cow : cows)
    {
        if(loc[cow.first][cow.second] < j++) continue;
        queue<pair<int,int>> q;
        q.push(cow);
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 1 || ny < 1 || ny > N || nx > N) continue;
                if(road[cur.first][cur.second][nx][ny]) continue;
                if(loc[nx][ny] <= loc[cur.first][cur.second]) continue;
                loc[nx][ny] = loc[cur.first][cur.second];
                q.push(make_pair(nx, ny));
            }
        }
    }
    int ans[101] = {0,};
    for(auto cow : cows)
    {
        ans[loc[cow.first][cow.second]]++;
    }
    int answer = 0;
    for(int i = 1; i < N; i++)
    {
        for(int j = i + 1; j <= N; j++)
        {
            if(!(!ans[i] || !ans[j]))
                answer += ans[i] * ans[j];
        }
    }
    cout << answer;
    return 0;
}
