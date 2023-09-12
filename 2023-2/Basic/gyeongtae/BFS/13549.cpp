#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool vis[100001];
queue <pair<int,int>> q;
int c, d;

void bfs(int a) {
	while (!q.empty()) {
		c = q.front().first;
		d = q.front().second;
		q.pop();
		if (c == m) {
			cout << d;
			break;
		}
		if (c - 1 >= 0 && c - 1 < 100001) {
			if (!vis[c - 1]) {
				vis[c - 1] = true;
				q.push(make_pair(c - 1, d + 1));
			}
		}
		if (c * 2 >= 0 && c * 2 < 100001) {
			if (!vis[c * 2]) {
				vis[c * 2] = true;
				q.push(make_pair(c * 2, d));
			}
		}
		if (c + 1 >= 0 && c + 1 < 100001) {
			if (!vis[c + 1]) {
				vis[c + 1] = true;
				q.push(make_pair(c + 1, d + 1));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	q.push(make_pair(n,0));
	vis[n] = true;
	bfs(n);
}
