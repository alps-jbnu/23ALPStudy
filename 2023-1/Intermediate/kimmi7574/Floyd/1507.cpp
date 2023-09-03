#include <bits/stdc++.h>
using namespace std;

int n;
int d[22][22];
bool isNotDirect[22][22] = { false, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int time, sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					cout << -1;
					return 0;
				}

				if (i != k && k != j && d[i][j] == d[i][k] + d[k][j])
					isNotDirect[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!isNotDirect[i][j])
				sum += d[i][j];
		}
	}

	cout << sum /2 ;

	return 0;
}