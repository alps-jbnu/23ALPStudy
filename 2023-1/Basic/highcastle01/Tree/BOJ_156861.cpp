#include<bits/stdc++.h>

using namespace std;

vector<int> connect[100001];
vector<bool> vis(100001);
int tsize[100001];

int countSubtreeNodes(int node)
{
	int ret = 1;
	
	if(tsize[node] != 0)
	{
		return tsize[node];
	}
	
	vis[node] = true;
	for(auto nxt : connect[node])
	{
		if(vis[nxt])
		{
			continue;
		}
		ret += countSubtreeNodes(nxt);
	}
	tsize[node] = ret;
	return ret;
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, r, q, i;
	
	cin >> n >> r >> q;
	
	for(i = 0; i < n - 1; i++)
	{
		int u, v;
		
		cin >> u >> v;
		connect[u].push_back(v);
		connect[v].push_back(u);
	}
	
	tsize[r] = countSubtreeNodes(r);
	
	for(i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		
		cout << tsize[x] << "\n";
	}
	
	return 0;
}
