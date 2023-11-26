#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[32002];
vector<int> result;
int indegree[32002];
int n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		result.push_back(cur);
		for (int nxt : adj[cur])
		{
			indegree[nxt]--;
			if (indegree[nxt] == 0)
				q.push(nxt);
		}
	}
	for (auto e : result)
		cout << e << ' ';

	return 0;
}
