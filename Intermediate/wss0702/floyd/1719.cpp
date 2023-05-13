#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int N, M, K;
int D[201][201];
int nxt[201][201];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		fill(D[i], D[i] + 1 + N, INF);
		D[i][i] = 0;
	}
	while (M--) {
		int a, b;
		int T;
		cin >> a >> b >> T;
		D[a][b] = T;
		D[b][a] = T;
		nxt[a][b] = b;
		nxt[b][a] = a;
	}
	
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) cout << "-" << " ";
			else cout << nxt[i][j] << " ";
		}
		cout << "\n";
	}
}
