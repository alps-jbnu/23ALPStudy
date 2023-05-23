#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#include<tuple>
#include<array>
#include<vector>
#include<string.h>
#define MAX 100005
using namespace std;
int v, e, k;
int indegree[1005];
vector<int>adj[1005];
queue<int> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	vector<int> result;
	for (int i = 0; i < e; i++) {
		int num;
		cin >> num;
		int v_1;
		cin >> v_1;
		for (int i = 0; i < num - 1; i++) {
			int v_2;
			cin >> v_2;
			adj[v_1].push_back(v_2);
			indegree[v_2]++;
			v_1 = v_2;
		}
	}
	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result.push_back(cur);
		for (int nxt : adj[cur]) {
			indegree[nxt]--;
			if (indegree[nxt] == 0)q.push(nxt);
		}
	}
	if (result.size() != v) cout << "0";
	else {
		for (auto ans: result) cout << ans << "\n";
	}

}
