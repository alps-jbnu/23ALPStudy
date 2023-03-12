#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAX 100 + 1
using namespace std;

int N, K;
int arr[MAX][11];
bool Visited[MAX][11];
vector<pii> bomb;
queue<pii> q;

int dxdy[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool BFS(int x, int y)
{
    bomb.push_back({ x, y });
    q.push({ x, y });
    Visited[x][y] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int dx = x + dxdy[i][0];
            int dy = y + dxdy[i][1];

            if (0 <= dx && N > dx && 0 <= dy && 10 > dy)
            {
                if (!Visited[dx][dy] && arr[dx][dy] == arr[x][y])
                {
                    q.push({ dx, dy });
                    bomb.push_back({ dx, dy });
                    Visited[dx][dy] = 1;
                }
            }
        }
    }
    if (bomb.size() >= K)
    {
        for (int i = 0; i < bomb.size(); i++)
            arr[bomb[i].first][bomb[i].second] = 0;
        return 1;
    }
    return 0;
}

void Solve()
{
    for (int j = 0; j < 10; j++)
    {
        for (int i = N - 2; i >= 0; i--)
        {
            if (arr[i][j])
            {
                int temp = i;

                while (temp + 1 < N && !arr[temp + 1][j])
                {
                    arr[temp + 1][j] = arr[temp][j];
                    arr[temp][j] = 0;
                    temp++;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (1)
    {
        bool explosion = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (arr[i][j])
                {
                    if (BFS(i, j))
                    {
                        explosion = 1;
                    }
                    memset(Visited, 0, sizeof(Visited));
                }
            }
        }
        if (!explosion) break;
        Solve();
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}