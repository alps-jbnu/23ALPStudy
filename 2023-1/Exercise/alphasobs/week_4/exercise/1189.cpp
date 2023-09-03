#include <bits/stdc++.h>
#define ll long long
const int MAX = 5 + 1;
const int INF = 1000000000;
using namespace std;

int R, C, K;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int Visited[MAX][MAX];
char arr[MAX][MAX];

int DFS(int y, int x)
{
    if(y == 0 && x == C - 1)
    {
        if(Visited[y][x] == K) return 1; 
        else return 0;
    }

    int temp = 0;
    for(int i = 0; i < 4; i++)
    {
        int cy = y + dir[i][0];
        int cx = x + dir[i][1];

        if(cy < 0 || cx < 0 || cy >= R || cx >= C || Visited[cy][cx] || arr[cy][cx] == 'T') continue;

        Visited[cy][cx] = Visited[y][x] + 1;
        temp += DFS(cy, cx);

        Visited[cy][cx] = 0;
    }
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    Visited[R - 1][0] = 1;
    cout << DFS(R - 1, 0);

    return 0;
}