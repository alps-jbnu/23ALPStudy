#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1001][1001];
int num[1001][1001];
bool vis[1001][1001][2];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
queue<pair<pair<int, int>, pair<int, int>>> q;

int bfs() {

	vis[0][0][0] = true;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int b = q.front().second.first;
		int c = q.front().second.second;
		q.pop();
		if (y == m - 1 && x == n - 1) {
			return c;
		}
		for (int i = 0;i < 4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) {
				continue;
			}
			if (map[ny][nx] == 1 && b==0) {
				vis[ny][nx][b + 1] = true;
				q.push(make_pair(make_pair(ny, nx), make_pair(b + 1, c + 1)));
			}
			else if (map[ny][nx] == 0 && vis[ny][nx][b] == false) {
				vis[ny][nx][b] = true;
				q.push(make_pair(make_pair(ny, nx), make_pair(b, c + 1)));
			}
		}
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n;
	//s = m * n;
	for (int i = 0;i < m;i++) {
		string a;
		cin >> a;
		for (int j = 0;j < n;j++) {
			map[i][j] = a[j] - '0';

		}
	}

	int a = bfs();

	cout << a;
}
