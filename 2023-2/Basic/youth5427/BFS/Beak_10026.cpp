#include <iostream>
#include <queue>
#include <string>
using namespace std;
bool vist[101][101];		// 방문여부
char board[101][101];			// 그림
int N;

int dx[4] = { 1,0,-1,0 };	// 방향
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;

void bfs(int i, int j){
	vist[i][j] = true;		//BFS
	Q.push({ i,j });
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {		// 상하좌우 탐색
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)	continue;		// 주어진 크기 넘어가기면 패스
			if (vist[nx][ny] == 1 || board[i][j] != board[nx][ny])continue;// (중요)방문 했거나 이전 칸과 다르면 패스
			vist[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}

int normal() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vist[i][j]) {
				bfs(i, j);
				count++;
			}
		}
	}
	return count;
}
int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	int Normal = normal();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'R')	board[i][j] = 'G';
			vist[i][j] = false;
		}
	}
	int strange = normal();
	cout << Normal<<" "<<strange;
	
}
