#include <iostream>
#include <tuple>
using namespace std;

int n, m, s, e, l;
const int INF = 0x3f3f3f3f;
int d[202][202];
tuple<int, int, int> edge[20002];		// 간선

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fill(d[i] + 1, d[i] + 1 + n, INF);
	for(int i = 1; i <= m; i++)
	{
		cin >> s >> e >> l;
		d[s][e] = min(d[s][e], l);
		d[e][s] = min(d[e][s], l);
		edge[i] = { s, e, l };
	}
	for (int i = 1; i <= n; i++)
		d[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	double ans = INF;
	for (int i = 1; i <= n; i++)		// i : 불을 붙이는 노드
	{
		double temp = 0;
		for (int j = 1; j <= m; j++)		// 모든 간선에 대해 검사
		{
			tie(s, e, l) = edge[j];
			temp = max(temp, static_cast<double>((l + d[i][s] + d[i][e])) / 2);
		}
		ans = min(ans, temp);			// 최대값중 최소값 구하기
	}
	cout.precision(1);
	cout << fixed;
	cout << ans;

	return 0;
}
