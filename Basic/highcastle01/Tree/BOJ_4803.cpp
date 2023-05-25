#include<bits/stdc++.h>

using namespace std;

vector<int> tree[501];
bool vis[501], isTree;

void dfs(int cur, int prev)
{
	for(int nxt : tree[cur])
	{
		if(nxt == prev)
		{
			continue;
		}
		if(vis[nxt])
		{
			isTree = false;
			continue;
		}
		vis[nxt] = true;
		dfs(nxt, cur);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, i, u, v, cnt, c = 1;
	
	while(1)
	{
		cin >> n >> m;
		
		if(n == 0 && m == 0)
		{
			break;
		}
		
		fill(vis, vis + n + 1, 0);
		for(i = 1; i <= n; i++)
		{
			tree[i].clear();
		}
		cnt = 0;
		
		for(i = 0; i < m; i++)
		{
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
			vis[i] = true;
			isTree = true;
			dfs(i, -1);
			cnt += isTree;
		}
		
		cout << "Case " << c++ << ": ";
		if(cnt == 0)
		{
			cout << "No trees." << "\n";
		}
		else if(cnt == 1)
		{
			cout << "There is one tree." << "\n";
		}
		else
		{
			cout << "A forest of " << cnt << " trees." << "\n";
		}
	}
	
	return 0;
}
