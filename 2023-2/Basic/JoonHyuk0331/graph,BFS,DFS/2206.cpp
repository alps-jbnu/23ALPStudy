#include <bits/stdc++.h>
using namespace std;
int n, m;

int vis[1002][1002][2];
int dist[1003][1003][2];
int board[1002][1002];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

typedef struct position
{
	int x;
	int y;
	bool break_wall;
}Pos;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			board[i][j] = row[j] - 48;//string 1을 int변수에 저장하면 1의 아스키코드 49가 저장되므로 미리 48뺌
		}
	}

	queue<Pos> q;
	q.push({ 0,0,0 });
	vis[0][0][0] = 1;
	while (!q.empty()) {
		Pos cur = q.front(); q.pop();

		//도착점 도달하면 종료
		if (cur.x == n - 1 && cur.y == m - 1) {
			cout << dist[n-1][m-1][cur.break_wall]+1;
			return 0;
		}

		//상하좌우탐색
		for (int dir = 0; dir < 4; dir++) {
			int x = cur.x + dx[dir];
			int y = cur.y + dy[dir];
			//범위를 넘어가면 안된다
			if (x < 0 || y < 0 || x >= n || y >= m)continue;
			//벽을 방문했을때
			if (board[x][y] == 1 && cur.break_wall == false) {//벽을 부순적 없다면
				//해당 좌표를 큐에 집어넣음
				q.push({ x,y,true });
				dist[x][y][true] = dist[cur.x][cur.y][cur.break_wall] + 1;
				vis[x][y][true] = 1;
				continue;
			}
			else if (board[x][y] == 1 && cur.break_wall == true) {//벽을 이미 부쉈다면
				//아무것도 하지 않는다
				continue;
			}
			//벽이 아닌곳을 방문했을때
			if (vis[x][y][cur.break_wall] == 0) {
				q.push({ x,y,cur.break_wall });
				dist[x][y][cur.break_wall] = dist[cur.x][cur.y][cur.break_wall] + 1;
				vis[x][y][cur.break_wall] = 1;
			}
		}
	}
	cout << -1;
	return 0;
}
