#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int n, m;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fill(d[i], d[i] + n + 1, INF);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}
	for (int i = 1; i <= n; i++) d[i][i] = 0;

	for (int k = 1; k <= n; k++)	// 거쳐가는 점
		for (int i = 1; i <= n; i++)	// 출발 점
			for (int j = 1; j <= n; j++)// 도착 점
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) cout << 0 << ' ';
			else cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
