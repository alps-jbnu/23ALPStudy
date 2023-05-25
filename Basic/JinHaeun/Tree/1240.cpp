#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, u, v, d;
vector<pair<int, int>> adj[100001];
int dist[1003] = { 0, };

int bfs(int s, int e) {
	int sum = 0;
	fill(dist, dist + 1003, -1);
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : adj[cur]) {
			if (dist[nxt.first] != -1) continue;
			dist[nxt.first] = dist[cur] + nxt.second;
			q.push(nxt.first);
		}
	}

	return dist[e];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
        
    }
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        cout << bfs(u, v) << '\n';
    }
  
}
