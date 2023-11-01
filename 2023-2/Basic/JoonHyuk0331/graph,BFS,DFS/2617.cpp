#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100];
vector<int> r_graph[100];
int vis[100];
int n, m;
int result;

void dfs(int i);
void dfs2(int i);

int main() {
	//그래프 입력
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);//단방향 그래프
		r_graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		dfs(i);
		dfs2(i);
	}
	
	cout << result;
}

void dfs(int i) {
	fill(vis, vis + 100, 0);
	int count=0;
	stack<int> s;
	s.push(i);
	vis[i] = true;
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		for (auto nxt : graph[cur]) {
			if (vis[nxt]) continue;
			s.push(nxt);
			vis[nxt] = true;
			count++;
		}
	}
	if (count >= (n + 1) / 2)
		result++;
}

void dfs2(int i) {
	fill(vis, vis + 100, 0);
	int count=0;
	stack<int> s;
	s.push(i);
	vis[i] = true;
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		for (auto nxt : r_graph[cur]) {
			if (vis[nxt]) continue;
			s.push(nxt);
			vis[nxt] = true;
			count++;
		}
	}
	if (count >= (n + 1) / 2)
		result++;
}
