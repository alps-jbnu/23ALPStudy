#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
char map[1001][1001];
int f_vis[1001][1001] = { 0 };
int j_vis[1001][1001] = { 0 };
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
queue <pair<int, int>> fq;
queue <pair<int, int>> jq;

void f_bfs() {
	int y = fq.front().first;
	int x = fq.front().second;

	while (!fq.empty()) {
		y = fq.front().first;
		x = fq.front().second;
		fq.pop();
		for (int i = 0;i < 4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) {
				continue;
			}
			if (map[ny][nx] == '#' || f_vis[ny][nx]) {
				continue;
			}
			fq.push(make_pair(ny,nx));
			f_vis[ny][nx] = f_vis[y][x] + 1;
		}
	}
}

int j_bfs() {
	int y = jq.front().first;
	int x = jq.front().second;

	while (!jq.empty()) {
		y = jq.front().first;
		x = jq.front().second;
		jq.pop();
		for (int i = 0;i < 4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) {
				return j_vis[y][x] ;
			}
			if (map[ny][nx] == '#' || j_vis[ny][nx]) {
				continue;
			}
			if (f_vis[ny][nx] && f_vis[ny][nx] <= j_vis[y][x] + 1) {
				continue;
			}
			jq.push(make_pair(ny, nx));
			j_vis[ny][nx] = j_vis[y][x] + 1;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c;
	cin >> c;

	for (int k = 0;k < c;k++) {
		cin >> n >> m;
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					jq.push(make_pair(i, j));
					j_vis[i][j] = 1;
				}
				if (map[i][j] == '*') {
					fq.push(make_pair(i, j));
					f_vis[i][j] = 1;
				}
			}
		}

		if (!fq.empty()) {
			f_bfs();
		}

		int a = j_bfs();
		if (a == -1) {
			cout << "IMPOSSIBLE" << "\n";
		}
		else {
			cout << a << "\n";
		}
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				f_vis[i][j] = 0;
				j_vis[i][j] = 0;
			}
		}
		while (!fq.empty()) {
			fq.pop();
		}
		while (!jq.empty()) {
			jq.pop();
		}
	}

	return 0;

}
