#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int nxt[105][105];
int n, m;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (d[a][b] > c) {
			d[a][b] = c;
			nxt[a][b] = b;
		}
	}
	

	for(int k = 1; k <= n; k++)
		for(int i = 1;i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) cout << 0 << ' ';
			else cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int s = i;
			int e = j;
			vector<int> result;
			if (nxt[s][e] == 0) true;
			else {
				result.push_back(s);
				while (1) {
					result.push_back(nxt[s][e]);
					if (nxt[s][e] == j) break;
					s = nxt[s][e];
				}
			}
			cout << result.size() << ' ';
			for (int e : result) cout << e << ' ';
			cout << '\n';
		}
	}



	return 0;
}
