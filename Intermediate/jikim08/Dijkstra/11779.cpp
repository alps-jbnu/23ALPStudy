#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int V, E, start, end;
	cin >> V >> E;
	vector<vector<pair<int, int>>> gp(V + 1);
	vector<int> dis(V + 1, INT_MAX);
	vector<int> pre(V + 1);
	int u, v, w;
	for (; E > 0; E--) {
		cin >> u >> v >> w;
		gp[u].push_back({ w,v });
	}
	cin >> start >> end;

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
			pre[next.second] = cur.second;
		}
	}

	cout << dis[end] << endl;
	vector<int> path;
	int cur = end;
	while (cur != start) {
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(cur);
	cout << path.size() << endl;
	for (int i = path.size()-1; i >= 0; i--) {
		cout << path[i] << " ";
	}

}
