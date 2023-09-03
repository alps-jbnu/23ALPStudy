#include <bits/stdc++.h>
using namespace std;

char board[1005][1005];
bool vis[1005][1005];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> q;
    int area_max = 0;
    int peri_max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '#' && vis[i][j] == false)
            {
                int tmp_area = 0;
                int tmp_perimeter = 0;
                q.push({i, j});
                vis[i][j] = true;
                while (!q.empty())
                {
                    tmp_area++;

                    auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {

                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (board[nx][ny] == '.' || nx == -1 || nx == n || ny == -1 || ny == n)
                        {
                            tmp_perimeter++;
                        }
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (vis[nx][ny] == true || board[nx][ny] == '.')
                            continue;
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
                bool chk = false;
                if (tmp_area > area_max)
                {
                    area_max = tmp_area;
                    peri_max = tmp_perimeter;
                }
                if (tmp_area == area_max)
                {
                    if (peri_max > tmp_perimeter)
                        peri_max = tmp_perimeter;
                }
            }
        }
    }
    cout << area_max << ' ' << peri_max;
}