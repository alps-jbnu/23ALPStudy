#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int board[205][205];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            board[i][j] = a;
        }
    }
    int s, x, y;
    cin >> s >> x >> y;

    vector<pair<int, pair<int, int>>> virus;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != 0)
            {
                virus.push_back({board[i][j], {i, j}});
            }
        }
    }
    sort(virus.begin(), virus.end());
    int time = 0;
    while (time < s)
    {
        int virusSize = virus.size();
        for (int i = 0; i < virusSize; i++)
        {
            int curVirus = virus[i].first;
            int curX = virus[i].second.first;
            int curY = virus[i].second.second;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (board[nx][ny] != 0)
                    continue;
                board[nx][ny] = curVirus;
                virus.push_back({curVirus, {nx, ny}});
            }
        }
        if (board[x - 1][y - 1])
            break;
        time++;
    }
    cout << board[x - 1][y - 1];
}