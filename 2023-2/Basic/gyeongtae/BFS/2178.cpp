#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
int map[501][501] = { 0, };
bool vis[501][501] = { 0, };
int num[501][501] = { 0, };
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
queue <pair<int, int>> q;
vector <int> v;
int s = 1;//그림의 넓이 구할거

void bfs(int y, int x) {
	q.push(make_pair(y, x));
	vis[y][x] = true;
	num[y][x] = 1;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				continue;
			}
			if (map[ny][nx] == 1 && vis[ny][nx] == 0) {
				q.push(make_pair(ny, nx));
				vis[ny][nx] = true;
				num[ny][nx] = num[y][x] + 1;
				s++;
			}
		}

	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			map[i][j] = row[j] - '0';
		}
	}

	bfs(0, 0);
	cout << num[n - 1][m - 1];
}
