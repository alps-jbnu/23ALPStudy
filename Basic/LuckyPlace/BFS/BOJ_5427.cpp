#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

char board[1001][1001];
int dist1[1001][1001];						// 불 거리
int dist2[1001][1001];						// 상근이 거리
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	queue<pair<int, int>> F;				// 불
	queue<pair<int, int>> SG;				// 상근이
	int n;				// 테스트케이스 개수
	cin >> n;
	while (n--)
	{
		int w, h;
		cin >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				dist1[i][j] = -1;
				dist2[i][j] = -1;
				if (board[i][j] == '@')
				{
					SG.push({ i,j });
					dist2[i][j] = 0;
				}
				if (board[i][j] == '*')
				{
					F.push({ i,j });
					dist1[i][j] = 0;
				}
			}
		}
		while (!F.empty())
		{
			auto current = F.front();
			F.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = current.first + dx[dir];
				int ny = current.second + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if (board[nx][ny] == '#' || dist1[nx][ny] >= 0)
					continue;
				dist1[nx][ny] = dist1[current.first][current.second] + 1;
				F.push({ nx, ny });
			}
		}
		bool escape = false;
		while (!SG.empty() && !escape)
		{
			auto current = SG.front();
			SG.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = current.first + dx[dir];
				int ny = current.second + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)			// 탈출 한 거
				{
					escape = true;
					cout << dist2[current.first][current.second] + 1 << '\n';
					break;
				}
				if (board[nx][ny] == '#' || dist2[nx][ny] >= 0)
					continue;
				if (dist1[nx][ny] != -1 && (dist2[current.first][current.second] + 1 >= dist1[nx][ny]))
					continue;
				dist2[nx][ny] = dist2[current.first][current.second] + 1;
				SG.push({ nx, ny });
			}
		}
		while (!SG.empty())			// 상근이 queue가 완전히 비워지지 않는 경우가 생기므로
			SG.pop();
		/*if (escape)				// 메모리 초과 원인
		{
			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					n = max(n, dist2[i][j]);
				}
			}
			cout << n << '\n';
		}*/
		if (!escape)
			cout << "IMPOSSIBLE" << '\n';
	}
	return 0;
}