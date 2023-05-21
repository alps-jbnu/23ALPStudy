#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <math.h>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> adj[10005];
bool chk[10005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t, n = 0, m;
	cin >> t;
	while (t--) {
		fill(chk, chk + n + 1, false);
		for (int i = 1; i <= n; i++) adj[i].clear();

		cin >> n >> m;

		while (m--) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back({ 1,b });
			adj[b].push_back({ 1,a });
		}

		int cnt = 0;
		int ans = 0;
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
			greater<tuple<int, int, int>>> pq;

		chk[1] = 1;
		for (auto nxt : adj[1]) pq.push({ nxt.X, 1, nxt.Y });

		while (cnt < n - 1) {
			int cost, a, b;
			tie(cost, a, b) = pq.top(); pq.pop();
			if (chk[b]) continue;
			chk[b] = 1;
			cnt++;
			ans += cost;
			for (auto nxt : adj[b]) {
				if (!chk[nxt.Y]) pq.push({ nxt.X, b, nxt.Y });
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
