#include<bits/stdc++.h>

using namespace std;

vector<int> check[101];
bool vis[101];

void dfs(int n)
{
	for(auto nxt : check[n])
	{
		if(vis[nxt])
		{
			continue;
		}
		vis[nxt] = 1;
		dfs(nxt);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, i, j, g;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> g;
			if(g)
			{
				check[i].push_back(j);
			}
		}
	}
	
	for (i = 0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        dfs(i);
        for (j = 0; j < n; j++)
        {
            if(vis[j])
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}
