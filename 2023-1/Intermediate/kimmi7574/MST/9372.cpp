#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n, m, a, b;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
		}

		cout << n - 1 << "\n";
		//MST 간선의 개수 = 정점의 개수 - 1
	}

	return 0;
}