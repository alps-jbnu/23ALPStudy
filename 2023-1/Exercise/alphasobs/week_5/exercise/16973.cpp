#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long int
const int MAX = 1000 + 1;
using namespace std;

int N, M;
int H, W, Sr, Sc, Fr, Fc;
int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
int arr[MAX][MAX], Visited[MAX][MAX];

bool Solve(int x, int y, int temp) 
{
	int a, b;

	switch (temp) 
    {
        case(0):
            a = x;
            b = y;
            for (int j = 0; j < H; j++) 
            {
                if (arr[a + j][b] == 1) return 0;
            }
            break;

        case(1):
            a = x;
            b = y + W - 1;
            if (y > M) return 0;
            for (int j = 0; j < H; j++) 
            {
                if (arr[a + j][b] == 1) return 0;
            }
            break;

        case(2):
            a = x;
            b = y;
            for (int j = 0; j < W; j++) 
            {
                if (arr[a][b + j] == 1) return 0;
            }
            break;

        case(3):
            a = x + H - 1;
            b = y;
            if (a > N) return 0;
            for (int j = 0; j < W; j++) 
            {
                if (arr[a][b + j] == 1) return 0;
            }
            break;
	}
	return 1;
}

int BFS(int x1, int y1, int x2, int y2)
{
    queue<pii> q;
    q.push({ x1, y1 });
    Visited[x1][y1] = 1;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == x2 && y == y2) return Visited[x][y] - 1;

        for(int i = 0; i < 4; i++)
        {
            int cx = x + dir[i][0];
            int cy = y + dir[i][1];

            if(cx < 1 || cx > N || cy < 1 || cy > M || arr[cx][cy] == 1) continue;

            if(!Visited[cx][cy] && Solve(cx, cy, i))
            {
                Visited[cx][cy] = Visited[x][y] + 1;
                q.push({ cx, cy });
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

    cout << BFS(Sr, Sc, Fr, Fc);

    return 0;
}