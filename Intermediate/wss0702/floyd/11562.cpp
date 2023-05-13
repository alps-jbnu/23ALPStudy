#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int N, M, K;
int D[251][251];
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
		bool T;
		cin >> a >> b >> T;
		D[a][b] = 0;
		D[b][a] = !T; // T가 0이면 1이 되서 양방향통행으로 바꿔야 하는 것을 표기
	}
	cin >> K;
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}
	}
	while (K--) {
		int s, e;
		cin >> s >> e;
		if (s == e) {
			cout << 0 << "\n";
			continue;
		}
		cout << D[s][e] << "\n";
	}
}
