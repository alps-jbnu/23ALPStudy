#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> result;
vector<int> adj[1002];
vector<int> temp;
int indegree[1002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int in;
			cin >> in;
			temp.push_back(in);
		}
		for (int j = 1; j < temp.size(); j++)
		{
			adj[temp[j - 1]].push_back(temp[j]);
			indegree[temp[j]]++;
		}
		temp.clear();
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
		for (auto nxt : adj[cur])
		{
			indegree[nxt]--;
			if (indegree[nxt] == 0)
				q.push(nxt);
		}
	}
	if (result.size() != n)
		cout << 0;
	else
		for (auto e : result)
			cout << e << "\n";
	

	return 0;
}
