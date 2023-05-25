#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int r, c, q;
int map[1005][1005];
int sum[1005][1005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> q;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> map[i][j];

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];

	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int ans = sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
		ans /= ((r2 - r1 + 1) * (c2 - c1 + 1));
		cout << ans << '\n';
	}

	return 0;
}
