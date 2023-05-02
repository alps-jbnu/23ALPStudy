#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

char board[101][101];
int dist[101][101] = {0,};
bool vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<pair<int, int>> check;
	int n, m, nx, ny, dir, i, j;
	
	cin >> n >> m;
	
	for(i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	
	vis[0][0] = true;
	check.push({0, 0});
	dist[0][0] = 0;
	
	while(!check.empty())
	{
		pair<int, int> cur = check.front(); check.pop();
		for(dir = 0; dir < 4; dir++)
		{
			nx = cur.X + dx[dir];
			ny = cur.Y + dy[dir];
			
			if(!vis[nx][ny] && board[nx][ny] == '1')
			{
				vis[nx][ny] = true;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				check.push({nx, ny});
			}
			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}
		}
	}
	
	cout << dist[n-1][m-1] + 1;
	return 0;
}
