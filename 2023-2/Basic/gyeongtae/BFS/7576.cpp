#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
int map[1001][1001] = { 0, };
int num[1001][1001] = { 0, };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1, };
queue <pair<int, int>> q;
vector <int> v;
int s = 0;//그림의 넓이 구할거
int x, y;

void bfs() {
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
			if (map[ny][nx] == 0) {
				q.push(make_pair(ny, nx));
				map[ny][nx] = 1;
				num[ny][nx] = num[y][x] + 1;
				s = max(s,num[ny][nx]);
				}
			}
		}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}
		}
	}

	cout << s;
}
