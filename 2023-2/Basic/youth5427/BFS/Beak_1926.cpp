#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };	// 방향
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int mx = 0;		// mx: 그림의 최댓값
	int num = 0;	// num: 그림의 수

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]==0 || vis[i][j])	continue;		// 색칠이 안되어 있거나, 방문했었으면 패스
			num++;											// 색칠이 되어 있고, 방문 한 곳! = 그림
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i,j });

			int area = 0;							// area: 그림 넓이
			while (!Q.empty()) {					// 비어있지 않을때
				area++;
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {		// 상하좌우 탐색
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;		// 주어진 크기 넘어가기
					if (vis[nx][ny] || board[nx][ny] != 1)	continue;			// 방문 했던곳이나 그림이 아닌 곳은 패스
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
			mx = max(mx, area);
		}
	}
	cout << num << '\n' << mx;
}
