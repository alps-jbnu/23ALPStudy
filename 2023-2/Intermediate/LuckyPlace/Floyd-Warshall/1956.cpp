#include <iostream>
#include <vector>
using namespace std;

int INF = 0x3f3f3f3f;
int town[405][405];
vector<pair<int, int>> adj[405];
int v, e, a, b, c;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 1; i <= v; i++)
		fill(town[i], town[i] + 1 + v, INF);
	while (e--)
	{
		cin >> a >> b >> c;
		town[a][b] = c;
	}
	for (int i = 1; i <= v; i++)
		town[i][i] = 0;

	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				town[i][j] = min(town[i][j], town[i][k] + town[k][j]);
	
	// i -> j로 가는 길과 j -> i로 가는 길이 둘 다 존재한다면 사이클이 있다.
	int ans = INF;
	for(int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
		{
			if (i != j)
				ans = min(ans, town[i][j] + town[j][i]);
		}
	
	if (ans == INF)
		cout << -1;
	else
		cout << ans;
	return 0;
}
