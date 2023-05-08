#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vertex[501];
int dist[501] = { 0, };

int main(void)
{
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		vertex[u].push_back(v);
		vertex[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto next : vertex[cur])
		{
			if (dist[next] > 0)
				continue;
			q.push(next);
			dist[next] = dist[cur] + 1;
		}
	}
	int num = 0;
	for (int i = 2; i <= n; i++)
	{
		if (dist[i] > 0 && dist[i] <= 2)
			num++;
	}
	cout << num << endl;
	return 0;
}