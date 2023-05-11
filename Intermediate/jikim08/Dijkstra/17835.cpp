#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> dijkstra(int v, vector<vector<pair<int, int>>> gp, vector<int> K) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dis(v+1, INT_MAX);
	
	for (int i : K) {
		dis[i] = 0;
		pq.push({ dis[i], i });
	}
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (dis[cur.second] != cur.first)	continue;
		for (auto next : gp[cur.second]) {
			if (dis[next.second] <= dis[cur.second] + next.first)	continue;
			dis[next.second] = dis[cur.second] + next.first;
			pq.push({ dis[next.second], next.second });
		}
	}

	return dis;

}

int main() {
	
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<pair<int,int>>> gp(N+1);
	int a, b, t;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> t;
		gp[b].push_back({ t,a });
	}
	vector<int> interview;
	int iv;
	for (int i = 0; i < K; i++) {
		cin >> iv;
		interview.push_back(iv);
	}
	vector<int> dis = dijkstra(N, gp, interview);

	int maxi = 1;
	int max = dis[1];
	for (int i = 2; i <= N; i++) {
		if (max < dis[i]) {
			max = dis[i];
			maxi = i;
		}
	}

	cout << maxi << '\n' << max;
}
