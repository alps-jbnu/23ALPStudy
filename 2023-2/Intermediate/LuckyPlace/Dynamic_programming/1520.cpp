#include <iostream>
using namespace std;

int board[505][505];
int dp[505][505];
int dist[505][505];
int m, n;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int dfs(int x, int y)
{
	if (x == m && y == n)	// 도착했으면 1리턴
		return 1;
	if (dp[x][y] != -1)			// 이미 방문했다면 현재값 리턴
		return dp[x][y];
	dp[x][y] = 0;					// 방문 표시
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= m && ny <= n)
		{
			if (board[x][y] > board[nx][ny])
			{
				dist[nx][ny] = dist[x][y] + 1;
				dp[x][y] += dfs(nx, ny);			// 도착했을 경우에만 1이 추가된다.
			}
		}
	}

	return dp[x][y];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	cout << dfs(1, 1);
	
	return 0;
}
