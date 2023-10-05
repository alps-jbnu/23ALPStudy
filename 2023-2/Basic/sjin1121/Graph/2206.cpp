#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#define Max 1001
using namespace std;

int n, m, a[Max][Max], visited[Max][Max][2], ok, ret, y, x, smash;
queue<tuple<int, int, int>>q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			a[i][j] = str[j - 1] - '0';
		}
	}
	q.push(make_tuple(1, 1, 0));
	while (q.size()) {
		tie(y, x, smash) = q.front();
		q.pop();
		if (y == n && x == m) {
			ok = true; // 끝점까지 도달
			ret = visited[n][m][smash] + 1; //(0,0)을 1로 봐야하니까 +1
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny <= 0 || nx <= 0 || ny > n || nx > m)continue;
			if (visited[ny][nx][smash]) continue;
			if (a[ny][nx] == 0)
			{
				visited[ny][nx][smash] = visited[y][x][smash] + 1;
				q.push(make_tuple(ny, nx, smash));
			}
			else if (a[ny][nx] == 1) {
				if (smash == 1) continue;
				visited[ny][nx][smash + 1] = visited[y][x][smash] + 1;
				q.push(make_tuple(ny, nx, smash + 1));

			}

		}
	}

	if (ok)
		cout << ret;
	else
		cout << "-1";
}
