#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

#define X first
#define Y second

int T, n, m, w;
vector<int> adj[1005];
int deg[1005];
int tm[1005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> tm[i];
		while (m--) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			deg[b]++;
		}
		cin >> w;

		// { 끝나는 시간, 작업 번호 }
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (int i = 1; i <= n; i++) if (!deg[i]) pq.push({ tm[i],i });
		
		int ans = 0;
		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			ans = max(ans, cur.X);
			if (cur.Y == w) break;
			for (int nxt : adj[cur.Y]) {
				deg[nxt]--;
				if (!deg[nxt]) pq.push({ tm[nxt] + cur.X,nxt });
			}
		}

		cout << ans << '\n';

		for (int i = 0; i <= n; i++) {
			adj[i].clear();
			deg[i] = 0;
			tm[i] = 0;
		}
	}

	return 0;
}
