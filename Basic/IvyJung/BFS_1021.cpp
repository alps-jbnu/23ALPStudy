#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[51][51];
int check[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> qu;
int n, m, k;
void bfs(int x, int y) {
	qu.push({ x,y });
	check[x][y] = true;
	while (!qu.empty()) {
		int ox = qu.front().first;
		int oy = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int nx = ox + dx[i];
			int ny = oy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (arr[nx][ny] == 1&&!check[nx][ny]) {
				qu.push({ nx,ny });
				check[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n >> k;
		int ans = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1&&!check[i][j]) {
					bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
				check[i][j] = false;
			}
		}
	}
}