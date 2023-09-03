// Union find를 구현해야하는 줄 알고 중도포기함
#include <bits/stdc++.h>
using namespace std;

int N, M;
int gift;
char board[1005][1005];
int visited[1005][1005];

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

int getDir(char c)
{
    if (c == 'N')
    {
        return 0;
    }
    else if (c == 'W')
        return 1;
    else if (c == 'E')
        return 2;
    else
        return 3;
}

void move(int r, int c, int pathId)
{
    visited[r][c] = pathId;

    int dir = getDir(board[r][c]);
    int nr = r + dr[dir];
    int nc = c + dc[dir];

    if (visited[nr][nc] == 0)
    {
        move(nr, nc, pathId);
    }
    else if (visited[nr][nc] == pathId)
    {
        gift++;
    }
}
void solve()
{
    int pathId = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == 0)
            {
                pathId++;
                move(i, j, pathId);
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    solve();
    cout << gift;

    return 0;
}