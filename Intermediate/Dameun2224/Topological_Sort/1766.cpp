#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
vector<int> adj[32005];
vector<int> result;
int deg[32005]; // i가 받은 간선의 수

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	// 우선순위 큐 : 가능하면 쉬운 문제(번호가 빠른 문제)부터 풀어야 한다
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) if (!deg[i]) pq.push(i);

	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		cout << cur << ' ';
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (!deg[nxt]) pq.push(nxt);
		}
	}

	return 0;
}
