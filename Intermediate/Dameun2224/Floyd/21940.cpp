#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, k;
int d[205][205];
int city[205];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = c;
	}
	cin >> k;
	for (int i = 1; i <= k; i++) cin >> city[i];

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}

	vector<pair<int, int>> result;
	for (int i = 1; i <= n; i++) {	// 모든 도시
		int mx = 0;
		for (int j = 1; j <= k; j++) {	// 친구들이 있는 도시
			if (d[i][city[j]] == INF || d[city[j]][i] == INF) continue;
			mx = max(mx, d[i][city[j]] + d[city[j]][i]);
		}
		result.push_back({ mx, i });
	}

	sort(result.begin(), result.end());
	int ans = result[0].first;
	for (auto cur : result) {
		if (cur.first > ans) break;
		cout << cur.second << ' ';
	}

	return 0;
}
