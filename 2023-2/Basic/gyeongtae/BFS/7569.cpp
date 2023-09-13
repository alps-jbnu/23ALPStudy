#include <iostream> 
#include <queue>
#include <algorithm>
using namespace std;

int m, n, h;
int map[102][102][102];
int num[102][102][102];
int dy[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int dh[6] = { 0,0,0,0,-1,1 };
queue<pair<pair<int, int>, int>> q;

int x, y, hi;

void bfs() {
	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		hi = q.front().second;
		q.pop();

		for (int i = 0;i < 6;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nh = hi + dh[i];
			if (ny < 0 || nx < 0 || nh < 0 || ny >= n || nx >= m ||nh>=h) {
				continue;
			}
			if (num[ny][nx][nh] >= 0) {
				continue;
			}
			q.push(make_pair(make_pair(ny, nx), nh));
			num[ny][nx][nh] = num[y][x][hi] + 1;
		}
	}
}

int main() {
	cin >> m >> n >> h;

	for (int k = 0;k < h;k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push(make_pair(make_pair(i, j), k));
				}
				if (map[i][j][k] == 0) {
					num[i][j][k] = -1;
				}
			}
		}
	}

	bfs();
	int s = 0;
	for (int k = 0;k < h;k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (num[i][j][k] == -1) {
					cout << "-1\n";
					return 0;
				}
				s = max(num[i][j][k], s);
			}
		}
	}
	cout << s;
}
