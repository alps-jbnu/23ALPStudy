#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int d[252][252];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k, u, v, b, s, e;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				d[i][j] = INF;
		}
	}


	for (int i = 0; i < m; i++) {
		cin >> u >> v >> b;
		d[u][v] = 0;
		if (b == 0)
			d[v][u] = 1; //단방향이면 양방향으로 바꾸어야하므로 역방향을 1로 설정(cnt계산위해)
		else {
			d[v][u] = 0;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> s >> e;
		cout << d[s][e] << "\n";
	}

	return 0;
}