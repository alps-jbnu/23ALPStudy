#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int a, b, c, d;
int map[101][101];
bool vis[101][101];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
queue <pair<int, int>> q;
vector <int> v;

void bfs(int y,int x) {
	int cnt = 1;
	q.push(make_pair(y, x));
	vis[y][x] = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				continue;
			}
			if (vis[ny][nx] == true || map[ny][nx] != 0) {
				continue;
			}
			vis[ny][nx] = true;
			q.push(make_pair(ny, nx));
			cnt++;
		}
	}
	v.push_back(cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> m >> n >> k;
	for (int i = 0;i < k;i++) {
		cin >> a >> b >> c >> d;
		for (int j = b;j < d;j++) {
			for (int l = a;l < c;l++) {
				map[l][j] = 1;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (map[i][j] == 0 && !vis[i][j])
				bfs(i, j);
		}
	}
	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (int i = 0;i < v.size();i++) {
		cout << v[i] << " ";
	}
}
