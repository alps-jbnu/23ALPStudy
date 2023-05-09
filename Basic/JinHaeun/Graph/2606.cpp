#include <bits/stdc++.h>
using namespace std;

vector<int> coco[1001];
bool vis[1001];
int n, m, num;

void dfs(int cur){
  	vis[cur] = true;
  	
  	for(auto nxt : coco[cur]){
    	if(vis[nxt]) continue;    
    	num++;
		dfs(nxt);
  	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n;
	cin >> m;
	
	while(m--) {
		int u, v;
		cin >> u >> v;
		coco[u].push_back(v);
		coco[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++)
    sort(coco[i].begin(), coco[i].end());
    
	dfs(1);
	cout << num;  	  	
}
