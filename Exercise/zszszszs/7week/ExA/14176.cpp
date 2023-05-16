#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool vis[251][251];
int board[251][251];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> q;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == false && board[i][j] == 1)
            {
                vis[i][j] = true;
                q.push({i, j});
                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir <= 7; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                            continue;
                        if (vis[nx][ny] == true || board[nx][ny] == 0)
                            continue;
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
                ans++;
            }
        }
    }

    cout << ans;
}