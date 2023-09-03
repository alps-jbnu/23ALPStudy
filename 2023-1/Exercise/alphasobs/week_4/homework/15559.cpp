#include <bits/stdc++.h>
const int MAX = 1000 + 1;
using namespace std;

int N, M, result = 0;
int Visited[MAX][MAX];
int dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
char arr[MAX][MAX];

int Dir(char ch)
{
    if (ch == 'N') return 0;
    else if (ch == 'W') return 1;
    else if (ch == 'E') return 2;
    else return 3;
}

void DFS(int y, int x, int path)
{
    Visited[y][x] = path;

    int num = Dir(arr[y][x]);
    int cy = y + dir[num][0];
    int cx = x + dir[num][1];

    if (!Visited[cy][cx]) DFS(cy, cx, path);
    else if (Visited[cy][cx] == path) result++;
}

void Solve()
{
    int temp = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!Visited[i][j])
            {
                temp++;
                DFS(i, j, temp);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    Solve();
    cout << result;

    return 0;
}