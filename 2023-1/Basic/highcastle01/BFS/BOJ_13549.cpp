#include<bits/stdc++.h>

using namespace std;

int dist[200002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int su, bro;
	deque<int> dq;
	
	cin >> su >> bro;
	
	memset(dist, -1, sizeof(dist));
	dq.push_back(su);
	dist[su] = 0;
	
	while(!dq.empty())
	{
		int cur = dq.front(); dq.pop_front();
		if(cur * 2 < 200000 && dist[cur*2] == -1)
		{
			dist[cur*2] = dist[cur];
			dq.push_front(cur*2);
		}
		
		for(int nxt : {cur-1, cur+1})
		{
			if(nxt < 0 || nxt >= 200000 || dist[nxt] != -1)
			{
				continue;
			}
			dist[nxt] = dist[cur] + 1;
			dq.push_back(nxt);
		}
	}
	
	cout << dist[bro];
	
	return 0;
}
