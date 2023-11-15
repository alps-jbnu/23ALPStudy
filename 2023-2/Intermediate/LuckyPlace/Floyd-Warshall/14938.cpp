#include <iostream>
#include <vector>
using namespace std;

int d[102][102];
int item[102];
int nxt[102][102];		// 경로 복원
bool vis[102];
const int INF = 0x3f3f3f3f;
int n, m, r, a, b, l;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> item[i];
	for (int i = 1; i <= n; i++)
		fill(d[i], d[i] + 1 + n, INF);
	while (r--)
	{
		cin >> a >> b >> l;
		d[a][b] = min(d[a][b], l);
		d[b][a] = min(d[b][a], l);
		nxt[a][b] = b;
		nxt[b][a] = a;
	}
	for (int i = 1; i <= n; i++)
		d[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					nxt[i][j] = nxt[i][k];
				}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(vis, vis + 1 + n, false);
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] > m)
				continue;
			int cur = i;
			while (cur != j) {
				vis[cur] = 1;
				cur = nxt[cur][j];
			}
			vis[j] = 1;
		}
		int temp = 0;
		for (int j = 1; j <= n; j++)
		{
			if (vis[j])
				temp += item[j];
		}
		ans = max(ans, temp);
	}
	cout << ans;

	return 0;
}
