#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[100001];
int p[100001];
void dfs(int root) {
	stack<int> s;
	s.push(root);
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		for (int nxt : adj[cur]) {
			if (p[cur] == nxt) continue;
			s.push(nxt);
			p[nxt] = cur;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << p[i] << '\n';
	}
}
