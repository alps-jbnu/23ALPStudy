#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vertex[101];
bool vis[101];

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
	int num = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (vis[cur])
			continue;
		vis[cur] = true;
		num++;
		for (auto next : vertex[cur])
		{
			if (vis[next])
				continue;
			q.push(next);
		}
	}
	cout << num - 1 << endl;
	return 0;
}