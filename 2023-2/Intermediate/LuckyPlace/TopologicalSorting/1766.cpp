#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> result;
vector<int> adj[32002];
int indegree[32002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			pq.push(i);
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		result.push_back(cur);
		for (auto nxt : adj[cur])
		{
			indegree[nxt]--;
			if (indegree[nxt] == 0)
				pq.push(nxt);
		}
	}
	for (auto e : result)
		cout << e << ' ';

	return 0;
}
