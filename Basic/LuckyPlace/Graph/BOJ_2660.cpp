#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> member[51];
int dist[51] = { -1, };
int score[51] = { 0, };

int main(void)
{
	int n;
	cin >> n;
	while (true)
	{
		int u, v;
		cin >> u >> v;
		if (u == -1 && v == -1)
			break;
		member[u].push_back(v);
		member[v].push_back(u);
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		fill(dist, dist + n + 2, -1);
		q.push(i);
		dist[i] = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto next : member[cur])
			{
				if (dist[next] >= 0)
					continue;
				q.push(next);
				dist[next] = dist[cur] + 1;
			}
		}
		score[i] = *max_element(dist + 1, dist + n + 1);
	}
	/*for (int i = 1; i <= n; i++)
		cout << score[i] << ' ';
	cout << endl;*/
	int min = *min_element(score + 1, score + n + 1);
	int count = 0;
	vector<int> candidate;
	for (int i = 1; i <= n; i++)
	{
		if (min == score[i])
		{
			count++;
			candidate.push_back(i);
		}
	}
	cout << min << ' ' << count << endl;
	for (int i = 0; i < candidate.size(); i++)
		cout << candidate[i] << ' ';

	return 0;
}