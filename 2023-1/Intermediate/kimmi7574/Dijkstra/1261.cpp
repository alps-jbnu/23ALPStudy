#include <bits/stdc++.h>
using namespace std;

int m, n, cnt = 0;
int v[102][102];
int dst[100][100];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

void func(int x, int y) {
	dst[x][y] = 0;
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
		greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0,{x, y} });

	while (!pq.empty()) {
		int count = pq.top().first;
		int cur_x = pq.top().second.first;
		int cur_y = pq.top().second.second;
		pq.pop();

		if (dst[cur_x][cur_y] < count)
			continue;

		for (int i = 0; i < 4; i++) {
			int next_count;
			int next_x = cur_x + dir[i][0];
			int next_y = cur_y + dir[i][1];

			if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n) {
				if (v[next_x][next_y] == 0)
					next_count = dst[cur_x][cur_y];
				else
					next_count = dst[cur_x][cur_y] + 1;

				if (dst[next_x][next_y] > next_count) {
					pq.push({ next_count,{next_x, next_y} });
					dst[next_x][next_y] = next_count;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char ch;
			cin >> ch;
			v[i][j] = ch - '0';
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			dst[i][j] = 987654321;
		}
	}

	func(0, 0);

	cout << dst[m - 1][n - 1];
	return 0;
}