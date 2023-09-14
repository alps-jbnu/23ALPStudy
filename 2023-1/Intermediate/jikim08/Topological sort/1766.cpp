#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	vector<int> indegree(N + 1, 0);

	priority_queue<int, vector<int>, greater<int>> Q;

	int out, in;
	for (int i = 0; i < M; i++) {
		cin >> out >> in;
		graph[out].push_back(in);
		indegree[in]++;
	}

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		int cur = Q.top(); Q.pop();
		cout << cur << ' ';
		for (int nxt : graph[cur]) {
			indegree[nxt]--;
			if (indegree[nxt] == 0) {
				Q.push(nxt);
			}
		}
	}


}
