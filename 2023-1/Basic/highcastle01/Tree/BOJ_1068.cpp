#include<bits/stdc++.h>
using namespace std;

vector<int> tree[51];
int root, rem;

int dfs(int p)
{
	int leaf = 0;
	if(p == rem)
	{
		return 0;
	}
	if(tree[p].empty())
	{
		return 1;
	}
	if(tree[p].size() == 1 && tree[p][0] == rem)
	{
		return 1;
	}
	for(auto tmp : tree[p])
	{
		leaf += dfs(tmp);
	}
	
	return leaf;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, u, v, i;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		cin >> u;
		if(u == -1)
		{
			root = i;
			continue;
		}
		
		tree[u].push_back(i);
	}
	cin >> rem;
	cout << dfs(root);
	
	return 0;
}
