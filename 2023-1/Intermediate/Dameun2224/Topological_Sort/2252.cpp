#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[32005];
// vector<int> result;
int deg[32005];


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!deg[i]) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << ' ';
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (!deg[nxt]) q.push(nxt);
		}
	}

	return 0;
}
