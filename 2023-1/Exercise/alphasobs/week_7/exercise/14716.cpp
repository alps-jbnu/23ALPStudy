#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
#define pip pair<int, pii>
const int MAX = 250 + 1;
using namespace std;

int N, M, result = 0;
int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
bool arr[MAX][MAX], Visited[MAX][MAX];
queue<pii> q;

void BFS(int x, int y)
{
    Visited[x][y] = 1;
    q.push({x, y});

    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++)
        {
            int dx = cx + dir[i][0];
            int dy = cy + dir[i][1];

            if(dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
            if(arr[dx][dy] && !Visited[dx][dy])
            {
                Visited[dx][dy] = 1;
                q.push({dx, dy});
            }
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(arr[i][j] && !Visited[i][j])
            {
                BFS(i, j);
                result++;
            }
        }
    }
    cout << result;

	return 0;
}  