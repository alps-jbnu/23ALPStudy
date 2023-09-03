/*
	Day: 2023.04.05
	참고 : 너비우선탐색(BFS) 연습문제2
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int dist[102][102];			// 출발점에서 거리
string board[102];			// 미로 판
int n, m;
int dx[4] = { 1,0,-1,0 };	// 방향
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);

	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	dist[0][0] = 0;
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {		// 상하좌우 탐색
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;		// 주어진 크기 넘어가기
			if (dist[nx][ny]>=0 || board[nx][ny] != '1')continue;		// 거리>0?? 이동할 수 없는 칸이면 패스
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << dist[n - 1][m - 1] + 1<<"\n";
}
