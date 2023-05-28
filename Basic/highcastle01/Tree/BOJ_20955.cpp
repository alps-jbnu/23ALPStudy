#include<bits/stdc++.h>

using namespace std;

vector<int> tree[100001];
bool vis[100001];

void dfs(int pos)
{
	if(vis[pos])
	{
		return;
	}
	vis[pos] = true;
	
	for(auto nxt : tree[pos])
	{
		dfs(nxt);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, i, gcnt = 0;
	
	cin >> n >> m;
	
	for(i = 0; i< m; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	for(i = 1; i <= n; i++)
	{
		if(vis[i])
		{
			continue;
		}
		dfs(i);
		gcnt++;
	}
	
	// 뉴런 그룹의 개수 + 이미 연결되어 있는 시냅스(간선)의 개수 
	cout << (gcnt - 1) + (m + gcnt -1) - (n - 1);
	
	return 0;
}
