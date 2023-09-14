#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int storage[1002][1002];
int dist[1002][1002];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
queue<pair<int, int>> Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	pair<int, int> current;
	int M, N;
	cin >> M >> N;

	for (int i = 0; i < N; i++)
		fill(dist[i], dist[i] + M, -1);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> storage[i][j];
			if (storage[i][j] == 1)
			{
				Q.push({ i,j });
				dist[i][j] = 0;	
			}
		}
	}
	
	while (!Q.empty())
	{
		current = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = current.first + dx[dir];
			int ny = current.second + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)		// 범위를 벗어나는 경우 continue
				continue;
			if (storage[nx][ny] == -1 || dist[nx][ny] >= 0)		// 토마토가 없는 경우와 지나간 곳인 경우
				continue;
			dist[nx][ny] = dist[current.first][current.second] + 1;
			Q.push({ nx, ny });
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (storage[i][j] == 0 && dist[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			else
				result = max(result, dist[i][j]);
		}
	}
	cout << result;

	return 0;
}