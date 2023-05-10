#include <bits/stdc++.h>
using namespace std;

int d[402][402];
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int v, e, a, b, c;
	cin >> v >> e;

	for (int i = 0; i <= v; i++) {
		for (int j = 0; j <= v; j++) {
			if (i != j)
				d[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		d[a][b] = c; // a --c--> b
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	long long min_num = INF;
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			if (i != k) {
				long long result = d[i][k] + d[k][i];
				if (min_num > result)
					min_num = result;
			}
		}
	}
	if (min_num == INF)
		cout << -1;
	else
		cout << min_num;
	return 0;
}