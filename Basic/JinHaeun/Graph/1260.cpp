#include <bits/stdc++.h>
using namespace std;

vector<int> coco[1001];
bool vis[1001];
int n, m, st;

void dfs(int cur){
  	vis[cur] = true;
  	cout << cur << ' ';
  	for(auto nxt : coco[cur]){
    	if(vis[nxt]) continue;    
    	dfs(nxt);
  	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n >> m >> st;
	while(m--) {
		int u, v;
		cin >> u >> v;
		coco[u].push_back(v);
		coco[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++)
    sort(coco[i].begin(), coco[i].end());
    
  	
	
	dfs(st);
  	cout << '\n';
  	  	
  	fill(vis+1, vis+n+1, false);

	//bfs
	queue<int> q;
	q.push(st);
	vis[st] = true;
	while(!q.empty()) {
		int cur = q.front();
		cout << cur << ' ';
		q.pop();
		for(auto nxt : coco[cur]) {
			if(vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
		}
	}
	
	
}
