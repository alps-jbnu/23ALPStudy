//오답
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
	cin >> v >> e;
	vector<vector<pair<int, int>>> gp(v + 1);
	
	int a, b, t;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> t;
		gp[a].push_back({ t,b });
		gp[b].push_back({ t,a });
	}
	int v1, v2;
	cin >> v1 >> v2;

	vector<int> first = dijkstra(v, gp, 1);
	vector<int> second = dijkstra(v, gp, v1);
	vector<int> third = dijkstra(v, gp, v2);

	int route1 = -1;
	int route2 = -1;
	if (first[v1] != INT_MAX && second[v2] != INT_MAX && third[v] != INT_MAX) {
		route1 = first[v1] + second[v2] + third[v];
	}
	else if (first[v2] != INT_MAX && second[v1] != INT_MAX && third[v] != INT_MAX) {
		route1 = first[v2] + second[v1] + third[v];
	}

	if (route1 == -1 && route2 == -1) {
		cout << -1;
	}
	else if (route1 != -1 && route2 == -1) {
		cout << route1;
	}
	else if (route1 == -1 && route2 != -1) {
		cout << route2;
	}
	else {
		cout << min(route1, route2);
	}

	
}
