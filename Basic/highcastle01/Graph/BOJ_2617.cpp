#include<bits/stdc++.h>

using namespace std;

#define MAX 100

int vis[MAX];

int bfs(vector<vector<int>> v, int x)
{
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	
	vis[x] = 1;
	q.push(x);
	
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		for(auto nxt : v[cur])
		{
			if(vis[nxt] != 0)
			{
				continue;
			}
			vis[nxt] = 1;
			q.push(nxt);
			cnt++;
		}
	}
	
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, u, v, ans = 0, i, big, small;
	
	cin >> n >> m;
	
	vector<vector<int>> light(n + 1);
	vector<vector<int>> heavy(n + 1);
	
	while(m--)
	{
		cin >> u >> v;
		
		light[u].push_back(v);
		heavy[v].push_back(u);
	}
	
	for(i = 1; i <= n; i++)
	{
		big = bfs(heavy, i);
		small = bfs(light, i);
		if(big > (n - 1) / 2 || small > (n - 1) / 2)
		{
			ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}
