#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N + 1);
	vector<int> indegree(N + 1, 0);
	
	int out, in;
	for (int i = 0; i < M; i++) {
		cin >> out >> in;
		graph[out].push_back(in);
		indegree[in]++;
	}

	queue<int> Q;
	vector<int> result;

	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0) Q.push(i);

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		result.push_back(cur);
		for (int nxt : graph[cur]) {
			indegree[nxt]--;
			if (indegree[nxt] == 0)	Q.push(nxt);
		}
	}

	for (int i : result) {
		cout << i << ' ';
	}

}
