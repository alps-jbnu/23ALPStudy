#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N + 1);
	vector<int> indegree(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int singer;
		cin >> singer;
		int in, out;
		cin >> in;
		for (int j = 0; j < singer - 1; j++) {
			cin >> out;
			graph[in].push_back(out);
			indegree[out]++;
			in = out;
		}
	}

	vector<int> result;
	queue<int> Q;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)	Q.push(i);
	}

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		result.push_back(cur);
		for (int nxt : graph[cur]) {
			indegree[nxt]--;
			if (indegree[nxt] == 0)	Q.push(nxt);
		}
	}

	if (result.size() != N) {
		cout << 0;
	}
	else {
		for (int i : result) {
			cout << i << endl;
		}
	}
	


}
