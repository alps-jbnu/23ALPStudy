#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MAX 101
int board[MAX][MAX];//필드
bool vis[MAX][MAX];//방문여부표시용
int dist[MAX][MAX];//거리체크
int n = 0, m = 0;//행과 열의 갯수(미로의 크기), 가변
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };//하 우 상 좌 순으로 검색(상 부터 시계방향)
queue<pair<int, int>> q;

void bfs(int xx, int yy)
{
	vis[xx][yy] = 1;//시작점을 방문했다고 명시
	q.push({ xx,yy });//방문 시 큐에 넣기
	dist[xx][yy] = 0;//시작점
	while (!q.empty()) {
		pair<int, int> cur = q.front();//큐의 최상단(가장오래된) 좌표 방문 (current)
		q.pop();//큐의 최상단 제거

		//풍차돌리기
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];//상하좌우 검색할 x좌표(new x)
			int ny = cur.Y + dy[dir];//상하좌우 할 y좌표(new y)
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {//nx가 0~n범위 벗어낫거나 ny가 0~m 범위 벗어낫을 때
				continue;
			}
			if (vis[nx][ny] == 1 || board[nx][ny] != 1) {//방문했거나 유효한 칸이 아니면
				continue;
			}
			vis[nx][ny] = 1;//방문한거면 1로 표기
			q.push({ nx,ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;//현재좌표의에 1더한 값이 상/하/좌/우 의 dist 거리값
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string data_row;
		cin >> data_row;

		for (int j = 0; j < m; j++) {
			board[i][j] = data_row[j] - '0';
		}
	}

	bfs(0, 0);

	cout << dist[n-1][m-1]+1;

}
