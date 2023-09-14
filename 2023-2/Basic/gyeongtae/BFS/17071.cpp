#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool vis[500001][2];
queue <pair<int, int>> q;
int c, d, g = 0,e;

int bfs(int a) {
	while (!q.empty()) {
		c = q.front().first;
		d = q.front().second;
		q.pop();
		if (m + d * (d + 1) / 2 > 500000) {
			return -1;
		}
		if (vis[m+d*(d+1)/2][d % 2]) {
			return d;
		}
		if (2 * c <= 500000 && !vis[2 * c][(d + 1) % 2]) {
			q.push({ 2 * c, d + 1 });
			vis[2 * c][(d + 1) % 2] = d + 1;
		}
		if (c + 1 <= 500000 && !vis[c + 1][(d + 1) % 2]) {
			q.push({ c + 1, d + 1 });
			vis[c + 1][(d + 1) % 2] = d + 1;
		}
		if (c - 1 >= 0 && !vis[c - 1][(d + 1) % 2]) {
			q.push({ c - 1, d + 1 });
			vis[c - 1][(d + 1) % 2] = d + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	q.push(make_pair(n, 0));
	vis[n][0] = true;
	cout<<bfs(n);

}
