#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[101][101];
int vis[101][101];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
int c, d, count1 = 10000;
vector <int> v;
int lab = 1;

void bfs(int a,int b, int h) {
	map[a][b] = h;

	for (int i = 0;i < 4;i++) {
		int ny = a + dy[i];
		int nx = b + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
			continue;
		}
		if (map[ny][nx] == -1) {
			bfs(ny, nx, h);
		}
	}
}
void bfs_1(int a) {
	queue <pair<int, int>> q;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (map[i][j] == a) {
				q.push(make_pair(i, j));
				vis[i][j] = 1;
			}
		}
	}
	int result = 0;
	while (!q.empty()) {
		int g = q.size();
		for (int i = 0;i < g;i++) {
			int k = q.front().first;
			int l = q.front().second;
			q.pop();
			for (int j = 0;j < 4;j++) {
				int ny = k + dy[j];
				int nx = l + dx[j];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
					continue;
				}
				if (map[ny][nx] != 0 && map[ny][nx] != a) {
					count1 = min(count1, result);
					return;
				}
				if (map[ny][nx] == 0 && vis[ny][nx] == 0) {
					vis[ny][nx] = 1;
					q.push(make_pair(ny, nx));					
				}
			}
		}
		result++;
	}
	count1 = min(count1, result);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n ;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (map[i][j] == -1) {
				bfs(i, j,lab++);
			}
		}
	}

	for (int i = 1;i < lab;i++) {
		fill(&vis[0][0], &vis[0][0] + 101 * 101, 0);
		bfs_1(i);
	}
	cout << count1;
}
