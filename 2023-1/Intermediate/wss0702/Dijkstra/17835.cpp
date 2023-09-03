#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const long long INF = 0x7f7f7f7f7f7f;
vector<pair<long long, int>> adj[100005];
int pre[1005];
int v, e, k;
long long d[100005];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
void di() {
	
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second]) { // cur 정점의 다음 정점들을 다 둘러봄 
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second });
		}
	}
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v >> e >> k;
	fill(d, d + v + 1, INF);
	while (e--) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		adj[v].push_back({ w,u });
	}
	
	for (int i = 0; i < k; i++) {
		int meetplace;
		cin >> meetplace;
		d[meetplace] = 0;
		pq.push({ d[meetplace], meetplace });
	}
	di();
	int cidx = max_element(d + 1, d + v + 1) - d;

	cout << cidx << "\n" << d[cidx];
}
