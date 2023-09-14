#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int V, E, start;
	cin >> V >> E >> start;
	vector<vector<pair<int, int>>> gp(V + 1);
	vector<int> dis(V + 1, INT_MAX);
	int u, v, w;
	for (; E > 0; E--) {
		cin >> u >> v >> w;
		gp[u].push_back({ w,v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dis[start] = 0;
	pq.push({ dis[start], start });

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();
		if (dis[cur.second] != cur.first)	continue;
		for (pair<int, int> next : gp[cur.second]) {
			if (dis[next.second] <= dis[cur.second] + next.first)	continue;
			dis[next.second] = dis[cur.second] + next.first;
			pq.push({ dis[next.second], next.second });
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dis[i] == INT_MAX)
			cout << "INF" << endl;
		else
			cout << dis[i] << endl;
	}

}
