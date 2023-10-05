#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, c, d;
vector<int> vis;
vector<vector<int>> v;

int bfs() {
	queue <int> q;
	vis[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int l = q.front();
		q.pop();
		if (l == a) {
			return vis[l];
		}
		for (int i = 0;i < v[l].size();i++) {
			int next = v[l][i];
			if (vis[next] == 0) {
				if (next > a) {
					vis[next] = vis[l];
				}
				else {
					vis[next] = vis[l] + 1;
				}
				q.push(next);
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int u;
	cin >> a >> b >> c;
	v.resize(a + c + 1); 
	vis.resize(a + c + 1, 0);
	for (int i = 1;i <= c;i++) {
		for (int j = 0;j < b;j++) {
			cin >> u;
			v[u].push_back(i + a);
			v[i + a].push_back(u);
		}
			
	}
	int f=bfs();
	cout << f << "\n";
}
