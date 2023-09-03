#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vertex[100001];
int parent[100001];

void bfs(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : vertex[cur])
		{
			if (parent[cur] == next)
				continue;
			parent[next] = cur;
			q.push(next);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int u, v;
	int loop = n - 1;
	while(loop--)
	{
		cin >> u >> v;
		vertex[u].push_back(v);
		vertex[v].push_back(u);
	}
	bfs(1);
	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}
	return 0;
}
