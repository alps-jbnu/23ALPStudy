#include<bits/stdc++.h>

using namespace std;

vector<int> check[501];
int vis[501];
int ans = 0;
int cnt = 0;

void dfs()
{
	stack<int> st;
	st.push(1);
	
	while(!st.empty())
	{
		int cur = st.top(); st.pop();
		vis[cur] = 1;
		if(cnt == 2)
		{
			break;
		}
		for(auto nxt: check[cur])
		{
			if(cur == 1)
			{
				st.push(nxt);
			}
			if(vis[nxt])
			{
				continue;
			}
			vis[nxt] = 1;
			ans++;
		}
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
	
	dfs();
	
	cout << ans;
	
	return 0;
}
