#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> dijkstra(int v, vector<vector<pair<int, int>>> gp, int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dis(v+1, INT_MAX);
	

	dis[start] = 0;
	pq.push({ dis[start], start });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (dis[cur.second] != cur.first)	continue;
		for (auto next : gp[cur.second]) {
			if (dis[next.second] <= dis[cur.second] + next.first)	continue;
			dis[next.second] = dis[cur.second] + next.first;
			pq.push({ dis[next.second], next.second });
		}
	}

	return dis;

}

int main() {
	int v, e, start;
	cin >> v >> e >> start;
	vector<vector<pair<int, int>>> gp(v + 1);
	vector<vector<pair<int, int>>> revgp(v + 1);
	int a, b, t;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> t;
		gp[a].push_back({ t,b });
		revgp[b].push_back({ t,a });
	}


	vector<int> goDis = dijkstra(v, gp, start);
	vector<int> comeDis = dijkstra(v, revgp, start);
	vector<int> Dis(v + 1, 0);
	for (int i = 1; i <= v; i++) {
		Dis[i] = goDis[i] + comeDis[i];
	}
	cout << *max_element(Dis.begin(), Dis.end());
}
