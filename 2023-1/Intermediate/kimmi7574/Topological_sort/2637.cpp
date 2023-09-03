#include <bits/stdc++.h>
using namespace std;

int n, m;
int in_degree[101];
int cnt[101];
vector<pair<int, int>> adj[101];
vector<int> result;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int prev, cur, k;
		cin >> prev >> cur >> k;
		adj[prev].push_back({ cur, k });
		in_degree[cur]++;
	}

	q.push(n);
	cnt[n] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (adj[cur].empty())
			result.push_back(cur);

		for (auto p : adj[cur]) {
			int next = p.first;
			int cost = p.second;
			cnt[next] += cnt[cur] * cost;
			
			if (--in_degree[next] == 0)
				q.push(next);
		}
	}

	sort(result.begin(), result.end());
	for (auto p : result)
		cout << p << " " << cnt[p] << "\n";

	return 0;
}