#include<bits/stdc++.h>

using namespace std;

vector<int> check[51];
vector<int> grp[51];
bool vis[51];

void bfs(int n)
{
	int i;
	queue<int> q;
	for(i = 1; i <= n; i++)
	{
		if(vis[i])
		{
			q.push(i);
		}
	}
	
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		for(auto nxt : grp[cur])
		{
			if(vis[nxt])
			{
				continue;
			}
			vis[nxt] = 1;
			q.push(nxt);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, i, f, x, pm, pre, next, cnt = 0;
	bool kn;
	
	cin >> n >> m >> f;
	
	for(i = 0; i < f; i++)
	{
		cin >> x;
		vis[x] = 1;
	}
	
	for(i = 0; i < m; i++)
	{
		cin >> pm;
		cin >> pre;
		check[i].push_back(pre);
		
		while(--pm)
		{
			cin >> next;
			check[i].push_back(next);
			grp[next].push_back(pre);
			grp[pre].push_back(next);
			swap(pre, next);
		}
	}
	
	bfs(n);
	
	for(i = 0; i < m; i++)
	{
		kn = 0;
		for(auto c : check[i])
		{
			if(vis[c])
			{
				kn = 1;
			}
		}
		if(!kn)
		{
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
