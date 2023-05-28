#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#include<tuple>
#include<vector>
#include<string.h>
#define MAX 10005
using namespace std;
int v, e, k;
int ans;
int indegree[MAX];
int cost[MAX];
int total[MAX];
vector<int> adj[MAX];
queue<int>q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> v>> e;
		for (int i = 1; i <= v; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < e; i++) {
			int v1,v2;
			cin >> v1 >> v2;
			adj[v1].push_back(v2);
			indegree[v2]++;
		}
		int target;
		cin >> target;
		for (int i = 1; i <= v; i++) {
			if (indegree[i] == 0)q.push(i);
		}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int nxt : adj[cur]) {
				total[nxt] = max(total[nxt], cost[cur] + total[cur]);
				indegree[nxt]--;
				if (!indegree[nxt])q.push(nxt);
			}
		}
		cout << total[target] + cost[target] << "\n";

		for (int i = 0; i <= v; i++) {
			adj[i].clear();
		}
		fill(total, total + v +5, 0);
		fill(cost, cost + v + 5, 0);
		fill(indegree, indegree + v + 5, 0);
		
	}
}

