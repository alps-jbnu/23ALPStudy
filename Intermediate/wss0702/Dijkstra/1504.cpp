#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[20005];
int v, e;
int v_1, v_2;
long long di(int st, int en) {
	int d[1005];
	fill(d, d + v + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	d[st] = 0;
	pq.push({ d[st],st });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second]) { // cur 정점의 다음 정점들을 다 둘러봄 
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second });
		}
	}
	return d[en];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;

	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
		adj[v].push_back({ w,u });
	}
	cin >> v_1 >> v_2;
	long long st_v_1 = di(1, v_1);
	long long v_1_v_2 = di(v_1, v_2);
	long long v_2_V = di(v_2, v);
	long long st_v_2 = di(1, v_2);// v_1을 먼저 들린다고 무조건 최소인게 아님.
	long long v_2_v_1 = di(v_2, v_1);
	long long v_1_V = di(v_1, v);
	long long ans1 = st_v_1 + v_1_v_2 + v_2_V;
	long long ans2 = st_v_2 + v_2_v_1 + v_1_V;
	long long ans = min(ans1, ans2);
    if(ans >= INF) cout << "-1";
	else cout << ans;
}
