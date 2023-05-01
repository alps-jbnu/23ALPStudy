#include<bits/stdc++.h>

using namespace std;

vector<int> nlist[51];
int cnt[51];
int n;

int bfs(int x)
{
	queue<int> q;
	
	int vis[51];
	int val;
	fill(vis, vis + n + 1, -1);
	
	vis[x] = 0;
	q.push(x);
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		for(auto s : nlist[cur])
		{
			if(vis[s] != -1)
			{
				continue;
			}
			vis[s] = vis[cur] + 1;
			q.push(s);
		}
	}
	
	val = *max_element(vis + 1, vis + n + 1);
	if(val == 0)
	{
		return 100;
	}
	else
	{
		return val;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i, a, b, mcnt;
	vector<int> candi;
	
	cin >> n;
	
	while(1)
	{
		cin >> a >> b;
		if(a == -1 && b == -1)
		{
			break;
		}
		nlist[a].push_back(b);
		nlist[b].push_back(a);
	}
	
	for(i = 0; i <= n; i++)
	{
		cnt[i] = bfs(i);
	}
	
	mcnt = *min_element(cnt + 1, cnt + n + 1);
	
	for(i = 1; i <= n; i++)
	{
		if(cnt[i] == mcnt)
		{
			candi.push_back(i);
		}
	}
	
	cout << mcnt << " " << candi.size() << "\n";
	for(auto c : candi)
	{
		cout << c << " ";
	}
	
	return 0;
}
