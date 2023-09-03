#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#include<tuple>
#include<array>
#include<vector>
#include<string.h>
#include<unordered_map>
#define MAX 32005
using namespace std;
int v, e, k;
int indegree[MAX];
vector<int>adj[MAX];
vector<int>child[1005];
priority_queue<int, vector<int>, greater<int>> pq;//작은 값 우선
queue<int> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		indegree[v2]++;
	}
	vector<int> result;
	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0) { 
			pq.push(i); 
		}
	}
	while (!pq.empty()) {
		 int cur = pq.top(); pq.pop();
			cout << cur << " ";
			for (int nxt : adj[cur]) {
				indegree[nxt]--;
				if (indegree[nxt] == 0) pq.push(nxt);
			}
		}
	}


