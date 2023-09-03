#include <bits/stdc++.h>
using namespace std;

int n;
int max_val = 0;
int d[505][505];	//d[i][j]: i,j번째 합까지의 최댓값
int s[505][505];	//i번째:행, j번째: 열

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> s[i][j];
		}
	}

	//초기값
	d[0][0] = 0;
	d[1][1] = s[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + s[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (max_val < d[n][i])
			max_val = d[n][i];
	}

	cout << max_val << '\n';
}