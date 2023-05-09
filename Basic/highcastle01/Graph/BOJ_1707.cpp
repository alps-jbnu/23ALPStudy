#include<bits/stdc++.h>

#define RED  1
#define BLUE 2
 
using namespace std;

vector<int> grp[20001];
int vis[200001];

void dfs(int start) 
{
    if (!vis[start])
	{
        vis[start] = RED;
    }
    for (auto nxt : grp[start]) 
	{
        if (!vis[nxt]) 
		{
            if (vis[start] == RED) 
			{
                vis[nxt] = BLUE;
            }
            else if (vis[start] == BLUE) 
			{
                vis[nxt] = RED;
            }
            dfs(nxt);
        }
    }
}
 
bool check(int v) 
{
    for (int i = 1; i <= v; i++) 
	{
        for (auto nxt : grp[i]) 
		{
            if (vis[i] == vis[nxt])
			{
                return 0;
            }
        }
    }
    return 1;
}
 
 
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k, v, e, u, x, i;
	
    cin >> k;
    while(k--)
	{
        cin >> v >> e;
        
        for (i = 0; i < e; i++) 
		{
            cin >> u >> x;
            grp[u].push_back(x);
            grp[x].push_back(u);
        }
 
        for (i = 1; i <= v; i++) 
		{ 
            if (!vis[i])
			{
                dfs(i);
            }
        }
 
        if (check(v)) 
		{
            cout << "YES\n";
        }
        else 
		{
            cout << "NO\n";
        }
 
        for (i = 0; i <= v; i++) 
		{
            grp[i].clear();
        }
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}
