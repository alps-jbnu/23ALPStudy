#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool vis[105][105];
char board[105][105];
int n, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> board[i][j];
        }
    }

    while (1)
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    fill(vis[k], vis[k] + 10, false);
                }
                if (board[i][j] == '0' || vis[i][j])
                    continue;
                char color = board[i][j];
                vector<pair<int, int>> v;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;
                while (!q.empty())
                {
                    auto cur = q.front();
                    v.push_back({cur.first, cur.second});
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= 10)
                            continue;
                        if (board[nx][ny] != color || vis[nx][ny])
                            continue;
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }

                if (v.size() >= k)
                {

                    flag = true;
                    for (int q = 0; q < v.size(); q++)
                    {
                        int x = v[q].first;
                        int y = v[q].second;
                        board[x][y] = '0';
                    }
                }
            }
        }
        for (int j = 0; j < 10; j++)
        {
            queue<char> q;
            for (int i = n - 1; i >= 0; i--)

            {
                if (board[i][j] != '0')
                {
                    q.push(board[i][j]);
                }
            }
            int x = n - 1;
            while (!q.empty())
            {
                char cur = q.front();

                q.pop();

                board[x--][j] = cur;
            }
            while (x >= 0)
            {
                board[x--][j] = '0';
            }
        }
        if (flag == false)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
}