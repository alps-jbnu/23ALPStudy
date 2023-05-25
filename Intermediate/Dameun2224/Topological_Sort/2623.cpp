#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, k;
vector<int> adj[32005];
vector<int> result;
int deg[32005];


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	while (m--) {
		cin >> k >> a >> b;
		if (k == 1) continue;
		adj[a].push_back(b);
		deg[b]++;
		a = b;
		for (int i = 3; i <= k; i++) {
			cin >> b;
			adj[a].push_back(b);
			deg[b]++;
			a = b;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!deg[i]) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result.push_back(cur);
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (!deg[nxt]) q.push(nxt);
		}
	}

	if (result.size() != n) cout << 0 << '\n';
	else for (int e : result) cout << e << '\n';

	return 0;
}
