#include <iostream>
#include <queue>
#include <string>
using namespace std;
int dist[1002][1002];			// 출발점에서 거리
int board[1002][1002];			// 토마토 판
int n, m;
int dx[4] = { 1,0,-1,0 };	// 방향
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				Q.push({ i,j });
			if (board[i][j] == 0)
				dist[i][j] = -1;
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {		// 상하좌우 탐색
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;		// 주어진 크기 넘어가기
			if (dist[nx][ny] >= 0)continue;		// 거리>0?? 이동할 수 없는 칸이면 패스
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}
	int sum = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1) {
				cout << -1;
				return 0;
			}
			sum = max(sum, dist[i][j]);
		}
	}
	cout << sum;
}
