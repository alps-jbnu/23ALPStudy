#include <bits/stdc++.h>
using namespace std;

int n;
int in_degree[10001];
int result[10001];
vector<int> adj[10001];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int time[10001];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i];
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int prev;
			cin >> prev;
			adj[prev].push_back(i);
			in_degree[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0)
			q.push(i);
		result[i] = time[i];
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto next: adj[cur]) {
			in_degree[next]--;
			result[next] = max(result[next], result[cur] + time[next]);

			if (in_degree[next] == 0)
				q.push(next);
		}
	}

	int ans = -1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, result[i]);
	}

	cout << ans;
	return 0;
}