#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, k;
int d[255][255];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = 0;
		d[b][a] = !c;	
		// c가 1인 경우 0, 0인 경우 1
		// 길이 있으면 0, 길이 없으면 1
		// 모든 연결된 길에 대해서 d[i][j] == 0,
		// 모든 연결되지 않은 길에 대해서 d[i][j] == 1
		
	}

	
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
			}
	// d[i][j]는 i에서 j로 가기 위해 이어야 할 다리의 수
	
	cin >> k;
	while (k--) {
		int s, e;
		cin >> s >> e;
		cout << d[s][e] << '\n';
	}

	return 0;
}
