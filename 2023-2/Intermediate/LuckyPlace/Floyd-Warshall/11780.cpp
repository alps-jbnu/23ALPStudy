#include <iostream>
#include <vector>
using namespace std;

int cities[105][105];
int nxt[105][105];
int n, m, a, b, c;
const int INF = 0x3f3f3f3f;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fill(cities[i], cities[i] + 1 + n, INF);
	while (m--)
	{
		cin >> a >> b >> c;
		cities[a][b] = min(cities[a][b], c);
		nxt[a][b] = b;
	}
	for (int i = 1; i <= n; i++)
		cities[i][i] = 0;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (cities[i][j] > cities[i][k] + cities[k][j])
				{
					cities[i][j] = min(cities[i][j], cities[i][k] + cities[k][j]);
					nxt[i][j] = nxt[i][k];
				}
			}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cities[i][j] == INF)
				cout << "0" << ' ';
			else
				cout << cities[i][j] << ' ';
		}
		cout << "\n";
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cities[i][j] == 0 || cities[i][j] == INF)
			{
				cout << 0 << "\n";			// i에서 j로 갈 수 없는 경우
				continue;
			}
			vector<int> path;
			int st = i;					// i에서 j로 가므로 i에서 출발
			while (st != j)				// j까지
			{
				path.push_back(st);
				st = nxt[st][j];
			}
			path.push_back(j);
			cout << path.size() << ' ';
			for (auto e : path)
				cout << e << ' ';
			cout << "\n";
		}
	}
	return 0;
}
