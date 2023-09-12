#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int m, n, l;
int map[1001][1001];
int num[1001][1001];
int vis[1001][1001][11][2];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
queue <tuple<int, int, int, int>> q;

int bfs() {
	vis[0][0][0][0] = true;
	q.push(make_tuple(0, 0, 0, 0));
	while (!q.empty()) {
		int x, y, c, sun;
		tie(x, y, c, sun) = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) {
				continue;
			}
			if (map[nx][ny] == 0 && vis[nx][ny][c][1 - sun] == 0) {
				vis[nx][ny][c][1 - sun] = vis[x][y][c][sun] + 1;
				q.push(make_tuple(nx, ny,  c, 1 - sun));
			}
			if (sun==0&&c+1<=l&&map[nx][ny] == 1 && vis[nx][ny][c+1][1-sun] == 0) {
				vis[nx][ny][c + 1][1 - sun] = vis[x][y][c][sun] + 1;
				q.push(make_tuple(nx,ny,  c + 1, 1 - sun));
			}
		}
		if (vis[x][y][c][1 - sun] == 0) {
			vis[x][y][c][1 - sun] = vis[x][y][c][sun] + 1;
			q.push(make_tuple( x,y, c, 1 - sun));
		}
	}
	int ans = -1;
	for (int i = 0; i <= l; i++) {
		for (int j = 0; j < 2; j++) {
			if (vis[n - 1][m - 1][i][j] == 0) continue;
			if (ans == -1 || ans > vis[n - 1][m - 1][i][j]) {
				ans = vis[n - 1][m - 1][i][j];
			}
		}
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> l;
	for (int i = 0;i < n;i++) {
		string a;
		cin >> a;
		for (int j = 0;j < m;j++) {
			map[i][j] = a[j] - '0';
		}
	}

	int a = bfs();

	cout << a;
}
