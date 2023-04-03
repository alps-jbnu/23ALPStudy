#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int dist[301][301];
int dx[8] = { 2,1,-1,-2,-1,-2,1,2 };
int dy[8] = { 1,2,2,1,-2,-1,-2,-1 };
queue<pair<int, int>> Q;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;						// 테스트 케이스의 개수
	cin >> n;
	while (n--)
	{
		int l;
		cin >> l;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				dist[i][j] = 0;
			}
		}
		int x_start, y_start;
		cin >> x_start >> y_start;
		int x_end, y_end;
		cin >> x_end >> y_end;
		Q.push({ x_start, y_start });
		dist[x_start][y_start] = 1;
		while (!Q.empty())
		{
			auto current = Q.front();
			Q.pop();
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = current.first + dx[dir];
				int ny = current.second + dy[dir];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l)
					continue;
				if (dist[nx][ny] > 0)
					continue;
				dist[nx][ny] = dist[current.first][current.second] + 1;
				Q.push({ nx, ny });
			}
		}
		cout << dist[x_end][y_end] - 1 << endl;
	}
	return 0;
}