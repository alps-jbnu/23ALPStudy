/*
	Day: 2023.04.05
	참고 : 너비우선탐색(BFS)
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int board[305][305];			
int n;				

int dx[8] = { 2, 2, -2, -2, -1, 1, -1, 1 };	// 방향
int dy[8] = { 1,-1, 1, -1, 2, 2, -2, -2 };
queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;
	cin >> N;
	while (N--) {

		cin >> n;
		for (int i = 0; i < n; i++) {		// 체스판 초기화
			for (int j = 0; j < n; j++) {
				board[i][j] = -1;
			}
		}
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;					// 0: 나이트가 있는 자리
		Q.push({ x,y });					// BFS
		int xx, yy;
		cin >> xx >> yy;
		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 8; dir++) {		// 상하좌우 탐색
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)	continue;		// 주어진 크기 넘어가기
				if (board[nx][ny]>=0)	continue;		// 나이트가 있는, 있던 자리
				board[nx][ny] = board[cur.first][cur.second]+1;
				Q.push({ nx,ny });
			}
		}
		cout << board[xx][yy]-1 << "\n";
		
	}
	return 0;
}
