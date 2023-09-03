#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;

int board[101][101][101];
int dist[101][101][101];
int dx[6] = { 0,0,1,0,0,-1 };	//001, 010, 100,00-1,0-10,-100
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 1,0,0,-1,0,0 };

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	queue<tuple<int, int, int>> Q;
	int m, n, h;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[j][k][i];
				if (board[j][k][i] == 1)
				{
					Q.push({ j,k,i });
					dist[j][k][i] = 1;
				}
			}
		}
	}

	/*cout << endl;*/
	/*for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cout << dist[j][k][i] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}*/

	while (!Q.empty())
	{
		auto current = Q.front();
		Q.pop();
		for (int dir = 0; dir < 6; dir++)
		{
			int nx = get<0>(current) + dx[dir];
			int ny = get<1>(current) + dy[dir];
			int nz = get<2>(current) + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
				continue;
			if (dist[nx][ny][nz] >= 1 || board[nx][ny][nz] == -1)
				continue;
			dist[nx][ny][nz] = dist[get<0>(current)][get<1>(current)][get<2>(current)] + 1;
			Q.push({ nx,ny,nz });
		}
	}

	/*cout << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cout << dist[j][k][i] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}*/
	int result = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dist[j][k][i] == 0 && board[j][k][i] == 0)
				{
					cout << -1;
					return 0;
				}
				result = max(dist[j][k][i], result);
			}
		}
	}
	cout << result - 1;

	return 0;
}