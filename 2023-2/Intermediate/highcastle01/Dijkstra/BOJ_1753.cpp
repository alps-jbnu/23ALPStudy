#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[20005];
int dist[20005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e, st; cin >> v >> e >> st;
	fill(dist, dist + v + 1, INF);

	while(e--)
	{
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

	dist[st] = 0;
	pq.push({dist[st], st});
	while(!pq.empty())
	{
		auto cur = pq.top(); pq.pop();

		if(dist[cur.Y] != cur.X)
		{
			continue;
		}
		for(auto nxt : adj[cur.Y])
		{
			if(dist[nxt.Y] <= dist[cur.Y] + nxt.X)
			{
				continue;
			}
			dist[nxt.Y] = dist[cur.Y] + nxt.X;
			pq.push({dist[nxt.Y], nxt.Y});
		}
	}

	for(int i = 1; i <= v; i++)
	{
		if(dist[i] == INF)
		{
			cout << "INF\n";
		}
		else
		{
			cout << dist[i] << "\n";
		}
	}

	return 0;
}
