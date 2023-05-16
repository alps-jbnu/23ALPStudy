#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int v, e, st;
// {비용, 정점 번호}
vector<pair<int, int>> adj[20005];
const int INF = 1e9 + 10;
int d[20005];	// 최단경로 저장

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> st;
	fill(d, d + v + 1, INF);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c,b});
	}

	priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[st] = 0;

	pq.push({ d[st],st });	// 0, st
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.Y] != cur.X) continue;
		// 현재 보는 점과 연결된 점들의 값 모두 확인
		for (auto nxt : adj[cur.Y]) {	
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << "\n";
	}

	return 0;
}
