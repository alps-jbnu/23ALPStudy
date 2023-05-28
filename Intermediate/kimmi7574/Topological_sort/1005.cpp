#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int time[1001];
		for (int i = 1; i <= n; i++)
			cin >> time[i];

		vector<int> adj[1001];
		int in_degree[1001] = { 0, };
		queue<int> q;
		int result[1001];

		while (k--) {
			int prev, cur;
			cin >> prev >> cur;
			adj[prev].push_back(cur);
			in_degree[cur]++;
		}

		int w;
		cin >> w;

		for (int i = 1; i <= n; i++) {
			if (in_degree[i] == 0)
				q.push(i);
			result[i] = time[i];
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto next : adj[cur]) {
				in_degree[next]--;
				result[next] = max(result[next], result[cur] + time[next]);

				if (in_degree[next] == 0)
					q.push(next);
			}
		}
		cout << result[w] << "\n";
	}

	return 0;
}