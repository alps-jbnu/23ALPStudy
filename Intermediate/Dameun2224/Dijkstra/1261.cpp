#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

// 왜 양방향에 모두 push 해줘야하는지?

#define X first
#define Y second

int n, m;
// {비용, 정점 번호}
vector<pair<int, int>> adj[10005];
vector<int> result;
const int INF = 0x3f3f3f3f;
int d[10005];	// 최단경로 저장

long long int func(int st, int en) {
	fill(d, d + n * m + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[st] = 0;
	pq.push({ d[st],st });	// 0, st
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.Y] != cur.X) continue;
		// 현재 보는 점과 연결된 점들의 값 모두 확인 (간선들)
		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}
	return d[en];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			int num = m * (i - 1) + j;
			if (i != 1) adj[num - m].push_back({ str[j - 1] - '0',num });
			if (j != 1) adj[num - 1].push_back({ str[j - 1] - '0',num });
			if (i != n) adj[num + m].push_back({ str[j - 1] - '0',num });
			if (j != m) adj[num + 1].push_back({ str[j - 1] - '0',num });
		}
	}

	cout << func(1, n * m) << '\n';

	return 0;
}
