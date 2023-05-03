#include <bits/stdc++.h>
using namespace std;

char board[5][5];
int r, c, k;
int vis[5][5];
int ans = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int dis)
{
    if (x == 0 && y == c - 1 && dis == k)
    {
        ans++;
        return;
    }
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            continue;
        if (board[nx][ny] == 'T')
            continue;
        if (vis[nx][ny] == true)
            continue;
        vis[nx][ny] = 1;
        dfs(nx, ny, dis + 1);
        vis[nx][ny] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
        }
    }
    vis[r - 1][0] = 1;
    dfs(r - 1, 0, 1);
    cout << ans;
}