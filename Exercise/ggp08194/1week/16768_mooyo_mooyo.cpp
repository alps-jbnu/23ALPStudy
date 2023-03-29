#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

char board[101][11];
char tmp[101][11];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[101][11];
queue<pair<int, int>> q;

int n;
int k;

int bfs(int X, int Y) {
	q.push({ X,Y });
	vis[X][Y] = true;
	int cnt = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx < 0 || nx > n || ny < 0 || ny > 10)continue;
			if (vis[nx][ny] == true) continue;
			if (board[cur.x][cur.y] != board[nx][ny]) continue;
			q.push({ nx,ny });
			vis[nx][ny] = true;
		}
	}
	return cnt;
}

void del(int X, int Y) {
	bool vis2[101][11];
	for (int i = 0; i < n; i++) {
		fill(vis2[i], vis2[i] + 11, false);
	}
	q.push({ X,Y });
	vis2[X][Y] = true;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx < 0 || nx > n || ny < 0 || ny > 10)continue;
			if (vis2[nx][ny] == true) continue;
			if (board[cur.x][cur.y] != board[nx][ny]) continue;
			q.push({ nx,ny });
			vis2[nx][ny] = true;
		}
		board[cur.x][cur.y] = '0';
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
		}
	}

	bool go = true;

	while (go) {
		go = false;

		for (int i = 0; i < n; i++) {
			fill(vis[i], vis[i] + 11, false);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] != '0' && vis[i][j] == false) {
					if (bfs(i, j) >= k) {
						del(i, j);
						go = true;
					}
				}
			}
		}

		for (int j = 0; j < 10; j++) {
			queue<char> vec;
			for (int i = n - 1; i >= 0; i--) {
				if (board[i][j] != '0') {
					vec.push(board[i][j]);
				}
			}
			for (int i = n - 1; i >= 0; i--) {
				if (!vec.empty()) {
					tmp[i][j] = vec.front();
					vec.pop();
				}
				else {
					tmp[i][j] = '0';
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				board[i][j] = tmp[i][j];
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}

}