#include<bits/stdc++.h>
using namespace std;
int n, m;
string board[105];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool vis[105][15];


int dfs(int x, int y, bool flag) {
	vis[x][y] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
 		int xx = dx[i] + x;
		int yy = dy[i] + y;
		if (xx < 0 || yy < 0 || xx >= n || yy > 10)	continue;
		if (vis[xx][yy])	continue;
		if (board[xx][yy] != board[x][y])	continue;
		ret += dfs(xx, yy, flag);
	}
	if (flag) {
		board[x][y] = '0';
	}
	return ret;

}


bool update() {
	memset(vis, 0, sizeof(vis));
	bool ret = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] != '0' && !vis[i][j]) {
				if (dfs(i, j, 0) >= m) {
					memset(vis, 0, sizeof(vis));
					ret = 1;
					dfs(i, j, 1);
				}
			}
		}
	}
	return ret;
}

void down() {
	for (int j = 0; j < 10; j++) {
		for (int i = n - 1; i >= 0; --i) {
			if (board[i][j] != '0') {
				for (int k = i; k + 1 < n && board[k + 1][j] == '0'; k++) {
					swap(board[k][j], board[k + 1][j]);
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	while (update()) {
		down();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
 }