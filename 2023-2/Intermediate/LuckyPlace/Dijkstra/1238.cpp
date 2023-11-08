#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define WEIGHT first
#define NODE second
using namespace std;

vector<pair<int, int>> adj[1005];
int dist[1005];
int pre[1005];
const int INF = 1e9 + 10;
int v, e, X, st;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> X;
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> go;
	for (st = 1; st <= v; st++)
	{
		fill(dist, dist + v + 1, INF);
		dist[st] = 0;
		pq.push({ dist[st], st });
		while (!pq.empty())
		{
			auto cur = pq.top();
			pq.pop();
			if (dist[cur.NODE] != cur.WEIGHT)
				continue;
			for (auto next : adj[cur.NODE])
			{
				if (dist[next.NODE] <= dist[cur.NODE] + next.WEIGHT)
					continue;
				dist[next.NODE] = dist[cur.NODE] + next.WEIGHT;
				pq.push({ dist[next.NODE], next.NODE });
			}
		}
		go.push_back(dist[X]);
	}
		fill(dist, dist + v + 1, INF);
		st = X;
		dist[st] = 0;
		pq.push({ dist[st], st });
		while (!pq.empty())
		{
			auto cur = pq.top();
			pq.pop();
			if (dist[cur.NODE] != cur.WEIGHT)
				continue;
			for (auto next : adj[cur.NODE])
			{
				if (dist[next.NODE] <= dist[cur.NODE] + next.WEIGHT)
					continue;
				dist[next.NODE] = dist[cur.NODE] + next.WEIGHT;
				pq.push({ dist[next.NODE], next.NODE });
			}
		}
		for (int i = 0; i < v; i++)
			go[i] += dist[i + 1];
		cout << *max_element(go.begin(), go.end());
	return 0;
}
