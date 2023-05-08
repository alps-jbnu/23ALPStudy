#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

#define X first
#define Y second

int v, e, en;
// {비용, 정점 번호}
vector<pair<int, int>> adj[1005];
vector<int> result;
const int INF = 1e9 + 10;
int d[1005];	// 최단경로 저장

int func(int st, int en) {
	fill(d, d + v + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[st] = 0;
	pq.push({ d[st],st });	// 0, st
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.Y] != cur.X) continue;
		// 현재 보는 점과 연결된 점들의 값 모두 확인 (간선들)
		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}
	return d[en];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> en;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c,b});
	}

	int ans = 0;
	for (int st = 1; st <= v; st++)
		ans = max(ans, func(st, en) + func(en, st));
	cout << ans << '\n';

	return 0;
}
