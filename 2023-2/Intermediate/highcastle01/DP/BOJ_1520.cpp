#include<bits/stdc++.h>

using namespace std;

int board[501][501];
int dp[501][501];
int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int BFS(int x, int y)
{
	if(dp[x][y] != -1)
	{
		return dp[x][y];
	}
	if(x == m-1 && y == n-1)
	{
		return 1;
	}

	dp[x][y] = 0;

	for(int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if(nx >= 0 && nx < m && ny >= 0 && ny < n)
		{
			if(board[nx][ny] < board[x][y])
			{
				dp[x][y] += BFS(nx, ny);
			}
		}
	}

	return dp[x][y];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans, i, j;

	cin >> m >> n;

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	cout << BFS(0, 0);

	return 0;
}
