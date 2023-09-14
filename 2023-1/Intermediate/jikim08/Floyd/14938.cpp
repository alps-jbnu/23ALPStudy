#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define INF INT_MAX

int main() {
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> item(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}

	vector<vector<int>> path(n + 1, vector<int>(n+1, 0));

	int a, b, l;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		dis[a][b] = dis[b][a] = l;
		path[a][b] = b;
		path[b][a] = a;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] == INF || dis[k][j] == INF)	continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	vector<int> maxitem(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dis[i][j] <= m) {
				maxitem[i] += item[j];
			}
		}
	}
	cout << *max_element(maxitem.begin(), maxitem.end());
}
