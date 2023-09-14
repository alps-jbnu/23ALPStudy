#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool vis[100001];
int prev1[100001];
queue <pair<int, int>> q;
vector <int> v;
int c, d;

void bfs(int a) {
	while (!q.empty()) {
		c = q.front().first;
		d = q.front().second;
		q.pop();
		if (c == m) {
			cout << d <<"\n";
			break;
		}
		if (c + 1 >= 0 && c + 1 < 100001) {
			if (!vis[c + 1]) {
				vis[c + 1] = true;
				prev1[c + 1] = c;
				q.push(make_pair(c + 1, d + 1));
			}
		}
		if (c - 1 >= 0 && c - 1 < 100001) {
			if (!vis[c - 1]) {
				vis[c - 1] = true;
				prev1[c - 1] = c;
				q.push(make_pair(c - 1, d + 1));
			}
		}
		if (c * 2 >= 0 && c * 2 < 100001) {
			if (!vis[c * 2]) {
				vis[c * 2] = true;
				prev1[c * 2] = c;
				q.push(make_pair(c * 2, d + 1));
			}
		}
	}
	for (int i = m;i != n;i = prev1[i]) {
		v.push_back(i);
	}
	v.push_back(n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	q.push(make_pair(n, 0));
	vis[n] = true;
	bfs(n);
	for (int i = 0;i < v.size();i++) {
		cout << v[v.size()-1-i] << " ";
	}
}
