#include<bits/stdc++.h>

using namespace std;

int mem[100001], state[100001];

void term(int x)
{
	int cur = x;
	while(1)
	{
		state[cur] = x;
		cur = mem[cur];
		
		if(state[cur] == x)
		{
			while(state[cur] != -1)
			{
				state[cur] = -1;
				cur = mem[cur];
			}
			return;
		}
		else if(state[cur] != 0)
		{
			return;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t, n, i, ans, cnt;
	
	cin >> t;
	
	while(t--)
	{
		ans = 0;
		cnt = 0;
		
		cin >> n;
		memset(state, 0, sizeof(state));
		for(i = 1; i <= n; i++)
		{
			cin >> mem[i];
		}
		
		for(i = 1; i <= n; i++)
		{
			if(state[i] == 0)
			{
				term(i);
			}
		}
		
		for(i = 1; i <= n; i++)
		{
			if(state[i] != -1)
			{
				cnt++;
			}
		}
		
		cout << cnt << "\n";
	}
	
	return 0;
}
