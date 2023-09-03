#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

char board[101][101];
bool is_visited[101][101] = { false };
bool rg_visited[101][101] = { false };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	int n;
	int normal_count(0);
	int rg_count(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (is_visited[i][j] == false)
			{
				is_visited[i][j] = true;
				Q.push({ i, j });
			}
			else
				continue;
			while (!Q.empty())
			{
				auto current = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = current.first + dx[dir];
					int ny = current.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)		//범위 밖으로 나가는 경우
						continue;
					if (board[current.first][current.second] != board[nx][ny])		// 색깔이 다른 경우
						continue;
					if (is_visited[nx][ny])			// 이미 방문한 경우
						continue;
					is_visited[nx][ny] = true;
					Q.push({ nx, ny });
				}
			}
			normal_count++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (rg_visited[i][j] == false)
			{
				rg_visited[i][j] = true;
				Q.push({ i, j });
			}
			else
				continue;
			while (!Q.empty())
			{
				auto current = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = current.first + dx[dir];
					int ny = current.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)		//범위 밖으로 나가는 경우
						continue;
					if (board[current.first][current.second] != board[nx][ny])		// 색깔이 다른 경우
						continue;
					if (rg_visited[nx][ny])			// 이미 방문한 경우
						continue;
					rg_visited[nx][ny] = true;
					Q.push({ nx, ny });
				}
			}
			rg_count++;
		}
	}
	cout << normal_count << ' ' << rg_count;
	return 0;
}