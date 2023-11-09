#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define WEIGHT first
#define NODE second
#define LL long long
using namespace std;

LL	 dist[100'005];
vector < pair < LL, LL >> adj[100'005];
const LL INF = 1e18;
LL v, e, k;
vector<LL> cities;

pair <LL, LL > dijkstra()
{
	priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<pair<LL, LL>>> pq;
	fill(dist, dist + v + 1, INF);
	/*dist[start] = 0;
	pq.push({ dist[start], start });*/
	// 면접장으로 시작을 한다.
	for (auto e : cities)
	{
		pq.push({ 0, e });
		dist[e] = 0;
	}
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
	// return {max_element(dist + 1, dist + 1 + v) -dist, *max_element(dist + 1, dist + 1 + v)};
	LL idx = 0, max = 0;
	for (int i = 1; i <= v; i++)
	{
		if (max < dist[i])
		{
			idx = i;
			max = dist[i];
		}
	}
	return { idx, max };
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++)
	{
		LL u, v, w;
		cin >> u >> v >> w;
		adj[v].push_back({ w, u });
	}
	for (int i = 0; i < k; i++)
	{
		LL in;
		cin >> in;
		cities.push_back(in);
	}
	auto max = dijkstra();
	cout << max.first << "\n" << max.second;
	return 0;
}
