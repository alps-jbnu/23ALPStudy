#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1002];
vector<int> result;
int deg[1002];
int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int a, b, num;
	while (m--) {
		cin >> num;
		if (num == 0) continue;
		cin >> a;
		for (int i = 0; i < num - 1; i++) {
			cin >> b;
			adj[a].push_back(b);
			cout << a << b;
			deg[b]++;
			a = b;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result.push_back(cur);
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}
	if (result.size() != n) cout << 0;
	else {
		for (int x : result) cout << x << '\n';
	}
}
