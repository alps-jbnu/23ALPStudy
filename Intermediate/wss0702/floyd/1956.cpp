#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int N, M;
int D[401][401];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		fill(D[i], D[i] + 1 + N, INF);
		D[i][i] = 0;
	}
	while (M--) {
		int a, b, T;
		cin >> a >> b >> T;
		D[a][b] = T;
	}
	
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}
	}
	
	int mn = INF;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			mn = min(mn, D[i][j] + D[j][i]);
		}
	}
	if(mn != INF)
		cout << mn;
	else cout << -1;
}
