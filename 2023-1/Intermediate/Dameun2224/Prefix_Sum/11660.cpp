#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num[1030][1030];
int sum[1030][1030];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> num[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + num[i - 1][j - 1];

	while (m--) {
		int r2, c2, r1, c1;
		cin >> r1 >> c1 >> r2 >> c2;
		cout << sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1] << '\n';
	}


	return 0;
}
