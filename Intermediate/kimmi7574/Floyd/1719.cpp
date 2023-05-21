#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
int d[202][202];
int place[202][202];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int u, v, c;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i != j)
				d[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		d[u][v] = c;
		d[v][u] = c;
		place[u][v] = v;
		place[v][u] = u;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					if (i != k)
					 place[i][j] = place[i][k];
					//두개의 경유지 거칠 수 있으므로 위처럼 작성
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << "- ";
			else
				cout << place[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}