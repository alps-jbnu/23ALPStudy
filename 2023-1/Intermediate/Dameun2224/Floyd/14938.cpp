#include <iostream>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, r;
int item[105];
int d[105][105];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) cin >> item[i];
	for (int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	while (r--) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = c;
		d[b][a] = c;
	}
	for(int k = 1;k <= n; k++)
		for(int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) continue;
			if (d[i][j] > m) continue;
			sum += item[j];
		}
		mx = max(mx, sum);
	}
	cout << mx << '\n';

	return 0;
}
