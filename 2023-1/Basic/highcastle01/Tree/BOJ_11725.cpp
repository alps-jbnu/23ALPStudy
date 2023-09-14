#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[100001];
int node[100001];

void dfs(int cur)
{
	for(int nxt : adj[cur])
	{
		if(node[cur] == nxt)
		{
			continue;
		}
		node[nxt] = cur;
		dfs(nxt);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i;
	
	cin >> n;
	for(i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for(i = 2; i <= n; i ++)
	{
		cout << node[i] << "\n";
	}
	
	return 0;
}
