#include<bits/stdc++.h>

using namespace std;

vector<int> check[101];
int vis[101];
int cnt = 0;

void dfs(int x)
{
	vis[x] = 1;
	for(auto nxt: check[x])
	{
		if(vis[nxt])
		{
			continue;
		}
		cnt ++;
		dfs(nxt);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, s, i, a, b;
	
	cin >> n >> s;
	
	for(i = 0; i < s; i++)
	{
		cin >> a >> b;
		check[a].push_back(b);
		check[b].push_back(a);
	}
	
	dfs(1);
	
	cout << cnt;
	
	return 0;
}
