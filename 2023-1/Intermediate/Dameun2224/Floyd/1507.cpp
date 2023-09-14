#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int n;
int d[25][25];
int u[25][25];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
			u[i][j] = d[i][j];
		}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (i == k || k == j) continue;
				if (d[i][j] > d[i][k] + d[k][j]) {
					cout << -1 << '\n';
					return 0;
 				}
				if (d[i][j] == d[i][k] + d[k][j]) u[i][j] = 0;
			}

	int ans = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++)
			ans += u[i][j];
	cout << ans << '\n';

	return 0;
}
