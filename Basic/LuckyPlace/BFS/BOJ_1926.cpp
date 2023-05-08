#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[502][502];

bool vis[502][502];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;
	int n, m;
	cin >> n >> m;		// n은 세로(행) m은 가로(열)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	int picture_num = 0;			// 그림의 개수(파란색의 개수)
	int area_max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)		// 파란색을 찾기 위한 2중 for문
		{
			if (board[i][j] == 0 || vis[i][j] == 1)		// 빨간색인 경우와 파란색이여도 체크된 경우 continue
				continue;
			Q.push({ i, j });
			vis[i][j] = 1;				// 찾은 곳이 일단 체크 안된 파란색이므로 체크
			picture_num++;
			int picture_area = 1;
			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)		// 범위 밖일 경우 continue
						continue;
					if (vis[nx][ny] || board[nx][ny] != 1)				// 이미 돌았거나 파란색이 아닐 경우 continue
						continue;
					vis[nx][ny] = 1;
					picture_area++;
					Q.push({ nx, ny });
				}
			}
			if (area_max < picture_area)
				area_max = picture_area;
		}
	}
	cout << picture_num << "\n" << area_max;

	return 0;
}