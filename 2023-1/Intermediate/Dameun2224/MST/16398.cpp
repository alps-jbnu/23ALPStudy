#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <math.h>
using namespace std;

#define X first
#define Y second

int n;
vector<pair<long long int, long long int>> adj[10005];
bool chk[10005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			int c;
			cin >> c;
			if (!c) continue;
			adj[a].push_back({ c, b });
		}
	}

	int cnt = 0;
	long long int ans = 0;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>>> pq;

	chk[1] = 1;
	for (auto nxt : adj[1]) pq.push({ nxt.X, 1, nxt.Y });

	while (cnt < n - 1) {
		long long int cost, a, b;
		tie(cost, a, b) = pq.top(); pq.pop();
		if (chk[b]) continue;
		chk[b] = 1;
		cnt++;
		ans += cost;
		for (auto nxt : adj[b]) {
			if (!chk[nxt.Y]) pq.push({ nxt.X, b, nxt.Y });
		}
	}

	cout << ans << '\n';

	return 0;
}
