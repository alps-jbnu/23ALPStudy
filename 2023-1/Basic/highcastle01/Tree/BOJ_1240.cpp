#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> tree[1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, i, j, u, v, d;
	
	cin >> n >> m;
	
	for(i = 0; i < n - 1; i++)
	{	
		cin >> u >> v >> d;
		
		tree[u].push_back({v, d});
		tree[v].push_back({u, d});
	}
	
	for(i = 0; i < m; i++)
	{
		queue<pair<int, int>> q;
		vector<bool> vis(n+1);
		
		cin >> u >> v;
		q.push({u, 0});
		vis[u] = true;
		
		while(!q.empty())
		{
			int cur = q.front().first;
			int dist = q.front().second;
			q.pop();
			
			if(cur == v)
			{
				cout << dist << "\n";
				break;
			}
			
			for(j = 0; j < tree[cur].size(); j++)
			{
				int nxt = tree[cur][j].first;
				int nxtdist = tree[cur][j].second;
				if(vis[nxt])
				{
					continue;
				}
				
				vis[nxt] = true;
				q.push({nxt, dist + nxtdist});
			}
		}
	}
	
	return 0;
}
