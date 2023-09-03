#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> computer[10001];
bool vis[10001] = { false, };

int main(void)
{
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		computer[v].push_back(u);
	}
	queue<int> q;
	vector<int> num;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
		vis[i] = true;
		int count = 0;
		while(!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto next : computer[cur])
			{
				if (vis[next])
					continue;
				q.push(next);
				vis[next] = true;
				count++;
			}
		}
		fill(vis, vis + n + 1, false);
		num.push_back(count);
	}
	int max_num = *max_element(num.begin(), num.end());
	for (int i = 1; i <= num.size(); i++)
	{
		if (max_num == num[i - 1])
			cout << i << ' ';
	}

	return 0;
}