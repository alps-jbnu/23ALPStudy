/*
	Day: 2023.05.04
	참고 : 너비우선탐색(BFS)_실패
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
bool vist[51][51] = { false };			// 방문여부
int board[51][51] = { 0 };			// 배추 밭
int n, m, k;				// 가로, 세로 , 배추밭

int dx[4] = { 1,0,-1,0 };	// 방향
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;
	while (N--) {
		cin >> n >> m >> k;
		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			board[x][y] = 1;
		}
		int count = 0;				// count: 지렁이 갯수

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && !vist[i][j]) {
					vist[i][j] = true;		//BFS
					Q.push({ i,j });
					while (!Q.empty()) {
						auto cur = Q.front();
						Q.pop();
						for (int dir = 0; dir < 4; dir++) {		// 상하좌우 탐색
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;		// 주어진 크기 넘어가기
							if (vist[nx][ny] || board[nx][ny] != 1)continue;		// 거리>0?? 이동할 수 없는 칸이면 패스
							vist[nx][ny] = true;
							Q.push({ nx,ny });
						}
					}
					count++;
				}
			}
		}
		cout << count << "\n";
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);
			fill(vist[i], vist[i] + m, false);
		}
	}
	return 0;
}
