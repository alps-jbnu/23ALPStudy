#include<iostream>
#include<vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int N, M, R; // M은 수색범위 
int D[101][101];
int item[101];
int nxt[101][101];
bool visited[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		int ITEM;
		cin >> ITEM;
		item[i] = ITEM;
		fill(D[i], D[i] + 1 + N, INF);
		D[i][i] = 0;
	}
	while (R--) {
		int a, b, I;
		cin >> a >> b >> I;
		D[a][b] = I;
		D[b][a] = I;
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
	int ans = 0;
	int tem;
	for (int i = 1; i <= N; i++) {
		tem = 0;
		fill(visited + 1, visited + N + 1, 0);
		for (int j = 1; j <= N; j++) {
			if (D[i][j] > M) continue;
			else {
				int cur = i;
				while (cur != j) {
					visited[cur] = true;
					cur = nxt[cur][j];
				}
				visited[j] = 1;
			}
		}
		for (int j = 1; j <= N; j++) {
			if (visited[j]) tem += item[j];
		}
		ans = max(ans, tem);
	}
	cout << ans;
}
