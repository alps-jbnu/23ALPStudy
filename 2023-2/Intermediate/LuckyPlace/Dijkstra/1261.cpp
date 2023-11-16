#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, cx, cy, cw;
int board[102][102];
int dist[102][102];
const int INF = 10e8;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dijkstra()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = INF;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.push({ 0, 1, 1 });
	dist[1][1] = 0;
	while (!pq.empty())
	{
		tie(cw, cx, cy) = pq.top();
		pq.pop();
		if (dist[cx][cy] != cw)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + cx;
			int ny = dy[i] + cy;
			if (nx < 1 || ny < 1 || nx > n || ny > m)
				continue;
			int nw = cw + board[nx][ny];
			if (dist[nx][ny] <= nw)
				continue;
			dist[nx][ny] = nw;
			pq.push({ nw, nx, ny});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	string str;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
			board[i][j + 1] = str[j] - '0';
	}
	dijkstra();
	cout << dist[n][m];
	return 0;
}
