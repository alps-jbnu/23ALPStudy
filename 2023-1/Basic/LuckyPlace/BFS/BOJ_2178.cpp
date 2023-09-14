#include <iostream>
#include <queue>
#include <utility>				// for std::pair
#include <string>
#include <algorithm>			// for std::fill
using namespace std;

string board[102];
int dist[102][102];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;						// N : 행		M : 열
	for (int i = 0; i < N; i++)
		cin >> board[i];					// board input
	for (int i = 0; i < N; i++)
		fill(dist[i], dist[i] + M, -1);		// 아마 iterator를 parameter로 받는듯
	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	dist[0][0] = 0;						// 시작점 저장
	while (!Q.empty())
	{
		pair<int, int> current = Q.front();
		Q.pop();
		for (int direction = 0; direction < 4; direction++)
		{
			int nx = current.first + dx[direction];
			int ny = current.second + dy[direction];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (board[nx][ny] != '1' || dist[nx][ny] >= 0)		// string 배열이므로 de-referencing 2번해서 사용가능
				continue;
			dist[nx][ny] = dist[current.first][current.second] + 1;
			Q.push({ nx, ny });
		}
	}
	cout << dist[N - 1][M - 1] + 1;			// 칸을 셀 때에는 시작 위치와 도착 위치도 포함하므로 +1
	return 0;
}