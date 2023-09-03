#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<long long, int>> vec[100002];
long long dst[100002];

priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
	greater<pair<long long, int>>> pq;

void func() {
	while (!pq.empty()) {
		int u, v;
		long long w, dw;
		tie(w, u) = pq.top();
		pq.pop();

		if (dst[u] != w)
			continue;
		for (auto next : vec[u]) {
			tie(dw, v) = next;
			dw += w;
			if (dw >= dst[v])
				continue;
			dst[v] = dw;
			pq.push({ dw, v });
		}
	}
}
/*간선을 모두 뒤집어 저장
  면접장소를 기준으로 거리를 0으로 세팅, 큐로 다익스트라이용
  후보찾기*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int u, v;
	long long c;

	cin >> n >> m >> k;
	fill(dst + 1, dst + n + 1, 1e18);

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		vec[v].push_back({ c, u });	//u,v 거꾸로 저장(거리, 정점)
	}

	for (int i = 0; i < k; i++) {	//면접장이 배치된 도시의 번호
		cin >> u;
		dst[u] = 0;
		pq.push({ dst[u], u });
	}

	func();

	int max_idx = max_element(dst + 1, dst + n + 1) - dst;
	cout << max_idx << "\n" << dst[max_idx];
	return 0;
}