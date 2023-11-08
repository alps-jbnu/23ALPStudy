#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define WEIGHT first
#define NODE second
using namespace std;

vector<pair<int, int>> adj[8005];
int dist[805];
const int INF = 1e7 + 10;
int v, e;

int Dijkstra(int start, int end)
{
	if (start == end)
		return 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(dist, dist + v + 1, INF);
	dist[start] = 0;
	pq.push({ dist[start], start });
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
	return dist[end];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}
	int v1, v2;
	cin >> v1 >> v2;
	int sum1 = 0;
	int sum2 = 0;

	sum1 += Dijkstra(1, v1);
	sum1 += Dijkstra(v1, v2);
	sum1 += Dijkstra(v2, v);

	sum2 += Dijkstra(1, v2);
	sum2 += Dijkstra(v2, v1);
	sum2 += Dijkstra(v1, v);

	int result = min(sum1, sum2);
	if (result >= INF)
		cout << -1;
	else
		cout << result;
	
	return 0;
}
