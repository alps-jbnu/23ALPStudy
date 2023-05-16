#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
long long c, high, low = 1;
vector<pair<long long, int>> edge[500002];
long long dst[100002];

bool func(long long x) {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>,
		greater<pair<long long, int>>> pq;

	memset(dst, 1e18, sizeof(dst));

	dst[a] = 0;
	pq.push({ 0, a });	//거리, 정점
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (dst[cur.second] != cur.first)
			continue;

		for (auto next : edge[cur.second]) {
			if (next.first > x)
				continue;
			next.first += cur.first;
			if (dst[next.second] <= next.first)
				continue;
			dst[next.second] = next.first;
			pq.push({ next.first, next.second });
		}
	}

	if (dst[b] > c)
		return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int v1, v2;
	long long amount;
	cin >> n >> m >> a >> b >> c;
	while (m--) {
		cin >> v1 >> v2 >> amount;
		edge[v1].push_back({ amount, v2 });
		edge[v2].push_back({ amount, v1 });
		high = max(high, amount);
	}

	while (low < high) {
		long long mid = (low + high) / 2;
		if (func(mid))
			high = mid;
		else
			low = mid + 1;
	}

	if (func(low))
		cout << low;
	else
		cout << -1;

	return 0;
}