#include <bits/stdc++.h>
using namespace std;

int n, m;
queue<int> q;
vector<int> result;
vector<int> adj[1001];
int in_degree[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int singer_num, prev, cur;
		cin >> singer_num;
		cin >> prev;
		singer_num--;

		while (singer_num--) {
			cin >> cur;
			adj[prev].push_back(cur);
			in_degree[cur]++;
			prev = cur;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		result.push_back(cur);
		for (auto& next : adj[cur]) {
			in_degree[next]--;
			if (in_degree[next] == 0)
				q.push(next);
		}
	}

	if (result.size() != n) {
		result.clear();
		result.push_back(0);
	}

	for (auto& e : result)
		cout << e << "\n";

	return 0;
}