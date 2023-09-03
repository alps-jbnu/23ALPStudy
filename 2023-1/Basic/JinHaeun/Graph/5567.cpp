#include <bits/stdc++.h>
using namespace std;

vector<int> v[1001];
bool vis[1001];
int n, m;
int depth;
int num = 0;

//재귀 dfs 
void dfs(int node, int depth) {
	if (depth > 2)	return;
	
	vis[node] = true;

	for (int i = 0; i < v[node].size(); i++) {
		int nxt = v[node][i];
		
		dfs(nxt, depth+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n;
	cin >> m;
	
	while(m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs(1, 0);
	
	for (int i = 1; i <= n; i++) {
		if (vis[i] == true)	
			num++;
	}
	
	cout << num - 1;  	//본인 빼기  
}
