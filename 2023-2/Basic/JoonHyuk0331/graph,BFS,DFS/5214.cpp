#include <bits/stdc++.h>
using namespace std;
vector<int> graph[101002];
int vis[101002];
int dist[101002];
int bfs(int n);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int input;
			cin >> input;
			graph[input].push_back(100002 + i);
			graph[100002 + i].push_back(input);
		}
	}
	cout << bfs(n);//매개변수n은 도착할 정점, 탐색시작점 아님!

	/*//debug
	for (int j = 1; j <= n; j++) {
		cout << j << " 와 연결된 정점: ";
		for (auto i : graph[j]) {
			cout << i << ' ';
		}
		cout << '\n';
	}*/
}

int bfs(int n) {
	dist[1] = 1;
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == n) return dist[cur];
		for (auto nxt : graph[cur]) {
			if (vis[nxt] == 1) continue;
			q.push(nxt);
			vis[nxt] = true;
			if (nxt >= 100002)//하이퍼튜브를 제외한 정점방문시, 거리+1
				dist[nxt] = dist[cur];
			else
				dist[nxt] = dist[cur] + 1;
		}
	}
	return -1;
}
