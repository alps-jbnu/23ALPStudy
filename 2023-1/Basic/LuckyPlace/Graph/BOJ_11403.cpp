#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int map[101][101];
bool vis[101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		q.push(i);
		fill(vis, vis + n + 1, false);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int j = 0; j < n; j++)
			{
				if (map[cur][j] == 0 || vis[j])
					continue;
				q.push(j);
				vis[j] = true;
			}
		}
		for (int k = 0; k < n; k++)
			cout << vis[k] << ' ';
		cout << endl;
	}
	return 0;
}