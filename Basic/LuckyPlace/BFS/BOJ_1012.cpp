#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<int> board[51];						// dynamic binding으로 배추 위치를 넣어햐해서 vector로 선언
bool is_visited[51][51];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void BFS(int a, int b, int n, int m)
{
	queue<pair<int, int>> Q;
	Q.push({ a, b });
	is_visited[a][b] == true;
	while (!Q.empty())
	{
		auto current = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = current.first + dx[dir];
			int ny = current.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (board[nx][ny] != 1 || is_visited[nx][ny] != false)
				continue;
			is_visited[nx][ny] = true;
			Q.push({ nx, ny });
		}
	}
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
	{
		board->clear();
		int count = 0;				// 지렁이 최소 마리 수
		int n, m;
		cin >> m >> n;							// n이 행, m이 열
		for (int i = 0; i < n; i++)
		{
			board[i].resize(m);
			for (int j = 0; j < m; j++)
			{
				board[i][j] = 0;
				is_visited[i][j] = false;
			}
		}
		int k;
		cin >> k;
		while (k--)
		{
			int a, b;
			cin >> b >> a;
			board[a][b] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && is_visited[i][j] != true)
				{
					BFS(i, j, n, m);
					count++;
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}