#include <iostream>
#include <math.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int d[205][205];
int nxt[205][205];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = c;	// 겹치는 경로는 없다고 가정
		d[b][a] = c;
		nxt[a][b] = b;
		nxt[b][a] = a;
	}
	
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					nxt[i][j] = nxt[i][k];
				}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (nxt[i][j] == 0) cout << "- ";
			else cout << nxt[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
