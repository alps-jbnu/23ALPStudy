// 1520

#include <iostream>

int n, m, result;
int dp[501][501];
int map[501][501];

int dx[] = { 0, 0, 1, -1 };
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y)         // dfs + dp 떠올림
{
	if (x == n - 1 && y == m - 1)
		return 1;
	if (dp[y][x] != -1)
		return dp[y][x];
	dp[y][x] = 0; // 갈 수 있는 경로 0개
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (map[ny][nx] < map[y][x]) // 이동 가능한 위치 : 이전보다 값이 작은 곳
				dp[y][x] += dfs(nx, ny);
		}
	}
	return dp[y][x];
}
int main()
{
	std::cin >> m >> n;      // 세로 가로 

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> map[i][j];
			dp[i][j] = -1;         // 초기화 
		}
	}
	result = dfs(0, 0);
	std::cout << result << "\n";

}
