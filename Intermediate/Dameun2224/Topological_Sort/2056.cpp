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

int n;
vector<int> adj[10005];
int deg[10005];
int tm[10005];
int cnt, ans;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int a = 1; a <= n; a++) {
		int b, t, m;
		cin >> t >> m;
		tm[a] = t;
		while (m--) {
			cin >> b;
			adj[b].push_back(a);
			deg[a]++;
		}
	}

	// { 끝나는 시간, 작업 번호 }
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 1; i <= n; i++) if (!deg[i]) pq.push({ tm[i],i });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		ans = max(ans, cur.X);
		for (int nxt : adj[cur.Y]) {
			deg[nxt]--;
			if (!deg[nxt]) pq.push({ tm[nxt] + cur.X,nxt });
		}
	}
 
	cout << ans << '\n';

	return 0;
}
