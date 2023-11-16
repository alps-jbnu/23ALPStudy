#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define INF 500000001
#define pii pair<int,int>
using namespace std;

int n, m, s, d;
vector<vector<pii>> g;
vector<vector<int>> prv;
bool check[501][501];

bool input() {
	g.clear(); prv.clear();
	cin >> n >> m;
	if (!n && !m)return false;
	memset(check, false, sizeof check);

	cin >> s >> d;
	g = vector<vector<pii>>(n + 1);

	for (int i = 0, u, v, p; i < m; i++) {
		cin >> u >> v >> p;
		g[u].push_back(make_pair(p, v)); // { 비용,정점 }
	}
	return true;
}

int dijkstra() {
	vector<int> dist(n + 1, INF);
	priority_queue<pii, vector<pii>, greater<>> pq; // { 비용,정점 }
	prv = vector<vector<int>>(n + 1);


	pq.push(make_pair(0, s));
	dist[s] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first; pq.pop();
		if (cost > dist[cur])continue;

		// 다음 경로 모두 확인
		for (auto x : g[cur]) {
			if (check[cur][x.second]) continue; // 체크되어 있으면 건너뜀

			// 다음 정점, 다음 비용 
			int next = x.second;
			int ncost = x.first;

			// 같은 경우 prv에 푸시
			if (dist[next] == dist[cur] + ncost) {
				prv[next].push_back(cur);
			}

			// 기존 경로보다 짧은 경우 prv 초기화, 푸시 / pq에 푸시 
			if (dist[next] > dist[cur] + ncost) {
				prv[next].clear();
				prv[next].push_back(cur);
				dist[next] = dist[cur] + ncost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	return dist[d] == INF ? -1 : dist[d];
}

// s에서 d로 가는 경로 모두 체크
void erase(int cur) {
	for (auto x : prv[cur]) {
		for (int i = 0; i < g[x].size(); i++) {
			if (g[x][i].second == cur && !check[x][cur]) {
				check[x][cur] = true;
				erase(x);
				break;
			}
		}
	}
}

int main() {
	while (input()) {
		dijkstra();
		erase(d);
		cout << dijkstra() << '\n';
	}
	return 0;
}
