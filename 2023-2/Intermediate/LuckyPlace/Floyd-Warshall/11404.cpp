#include <iostream>
#include <algorithm>
using namespace std;

int cities[105][105];
const int INF = 0x3f3f3f3f;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fill(cities[i], cities[i] + 1 + n, INF);
	while (m--)
	{
		cin >> a >> b >> c;
		cities[a][b] = min(cities[a][b], c);		// 겹치는 게 있어서 최솟값을 넣기 위해
	}
	for (int i = 1; i <= n; i++)
		cities[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cities[i][j] = min(cities[i][j], cities[k][j] + cities[i][k]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cities[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << cities[i][j] << ' ';
		}
		cout << "\n";
	}

	return 0;
}
