//#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
vector<int> adj[20001];
int color[20001];
int vs;
bool vis[20001];

void bfs1(int i) {
	queue<int> q;
	q.push(i);
	vis[i] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
			if (color[cur] == 0)
				color[nxt] = 1;
			else if (color[cur] == 1)
				color[nxt] = 0;
		}
	}
}

string bfs2() {
	for (int cur = 1; cur <= vs; cur++) {
		for (int nxt = 0; nxt < adj[cur].size(); nxt++) {
			int adj_vertex = adj[cur][nxt];
			if (color[cur] == color[adj_vertex]) {
				return "NO";
			}
		}
	}
	return "YES";
}

int main(void) {
	string flag;
	int k, e, u, v;
	
	
	cin >> k;
	for (int i = 0; i < k; i++) {
		memset(color, 0, sizeof(color));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i <= vs; i++) {
			adj[i].clear();
		}
		//방문기록
		cin >> vs >> e;
		for (int j = 0; j < e; j++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int l = 1; l <= vs; l++) {
			if (vis[l] == 0) {
				bfs1(l);
			}
		}
		flag = bfs2();
		cout << flag << '\n';
		//fill(color, color + 20001, 0);
	}
}
