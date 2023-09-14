#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector <int> map[100001];
vector <int> vis;
queue <int> q;
vector <pair<int,int>> v;
int s = 0;

void bfs(int x) {
	vis[x] = true;
	q.push(x);

	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < map[x].size(); i++) {
			int z = map[x][i];
			if (vis[z]==0) {
				vis[z] = true;
				s++;
				q.push(z);
			}
		}
	}
}

int main() {
	cin >> m >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		map[b].push_back(a);
	}
	int max = -1;
	for (int i = 1; i <= m; i++) {
		vis = vector<int>(m + 1, 0);
		bfs(i);
		v.push_back(make_pair(s,i));
		if (max < s) {
			max = s;
		}
		s = 0;
	}

	for (int i = 0; i < m; i++) {
		if (v[i].first== max) {
			cout << v[i].second << " ";
		}
	}
}
