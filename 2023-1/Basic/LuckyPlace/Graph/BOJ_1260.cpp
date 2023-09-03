#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> node[1005];
bool is_visited[1005];

void dfs(int start)
{
	stack<int> s;
	s.push(start);
	while (!s.empty())
	{
		int current = s.top();
		s.pop();
		if (is_visited[current])
			continue;
		is_visited[current] = true;
		cout << current << ' ';
		for (int i = node[current].size() - 1; i >= 0; i--)
		{
			int next = node[current][i];
			if (is_visited[next])
				continue;
			s.push(next);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	is_visited[start] = true;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		cout << current << ' ';
		for (auto next : node[current])
		{
			if (is_visited[next])
				continue;
			q.push(next);
			is_visited[next] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;			// n = 정점의 개수, m = 간선의 개수
	cin >> n >> m;
	int start;
	cin >> start;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		sort(node[i].begin(), node[i].end());
	dfs(start);
	for (int i = 1; i <= n; i++)
		is_visited[i] = false;			// is_visited 초기화
	cout << "\n";
	bfs(start);

	return 0;
}