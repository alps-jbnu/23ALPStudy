#include <bits/stdc++.h>
using namespace std;

int n, m;
int in_degree[32001];
vector<int> result;
vector<int> adj[32001];

void topologySort() {
	//차수가 0인 정점에서도 순서 존재 -> 우선순위 큐 이용
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0)
			pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		cout << cur << " ";

		for (auto next : adj[cur]) {
			in_degree[next]--;
			if (in_degree[next] == 0)
				pq.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int prev, cur;
	cin >> n >> m;
	while (m--) {
		cin >> prev >> cur;
		adj[prev].push_back(cur);
		in_degree[cur]++;
	}

	topologySort();

	return 0;
}