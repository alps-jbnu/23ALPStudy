#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, c, d;
int map[301][301];
bool vis[301][301];
int dy[8] = { -2,-2,-1,-1,1,1,2,2 };
int dx[8] = { 1,-1,-2,2,-2,2,1,-1 };
queue <pair<int, int>> q;

void bfs(int a) {
	int y = q.front().first;
	int x = q.front().second;
	vis[y][x] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == c && x == d) {
			cout << map[y][x] << "\n";
			return;
		}
		for (int i = 0;i < 8;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= a || nx >= a) {
				continue;
			}
			if (vis[ny][nx] == true || map[ny][nx] != 0) {
				continue;
			}
			map[ny][nx] = map[y][x] + 1;
			vis[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> m >> a >> b >> c >> d;
		q.push(make_pair(a, b));

		bfs(m);
		while (!q.empty()) {
			q.pop();
		}
		for (int j = 0;j < 301;j++) {
			for (int k = 0;k < 301;k++) {
				map[j][k] = 0;
				vis[j][k] = false;
			}
		}
	}
}
