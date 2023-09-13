#include <iostream> 
#include <queue>
#include <algorithm>
using namespace std;

int m, n, h;
char map[31][31][31];
int num[31][31][31] = { 0 };
int dy[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int dh[6] = { 0,0,0,0,-1,1 };
queue<pair<pair<int, int>, int>> q;

int x, y, hi;

int bfs() {
	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		hi = q.front().second;
		q.pop();
		if (map[y][x][hi] == 'E') {
			return num[y][x][hi];
		}
		for (int i = 0;i < 6;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nh = hi + dh[i];
			if (ny < 0 || nx < 0 || nh < 0 || ny >= n || nx >= m || nh >= h) {
				continue;
			}
			if (map[ny][nx][nh] == '#'|| num[ny][nx][nh]!=0) {
				continue;
			}
			q.push(make_pair(make_pair(ny, nx), nh));
			num[ny][nx][nh] = num[y][x][hi] + 1;
		}
	}
	return -1;
}

int main() {
	while (1) {
		cin >> h >> n >> m ;
		if (h == 0 && n == 0 && m == 0) {
			break;
		}
		for (int k = 0;k < h;k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') {
						q.push(make_pair(make_pair(i, j), k));
					}
				}
			}
		}
		int a = bfs();
		if (a == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout <<"Escaped in "<< a << " minute(s).\n";
		}
		while (!q.empty()) {
			q.pop();
		}
		for (int k = 0;k < h;k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					num[i][j][k] = 0;
				}
			}
		}
	}
}
