#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int h[1005][3];
int a[1005][3];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) cin >> h[i][j];
	}

	a[1][0] = h[1][0];
	a[1][1] = h[1][1];
	a[1][2] = h[1][2];


	for (int i = 2; i <= n; i++) {
		a[i][0] = min(a[i - 1][1], a[i - 1][2]) + h[i][0];
		a[i][1] = min(a[i - 1][0], a[i - 1][2]) + h[i][1];
		a[i][2] = min(a[i - 1][0], a[i - 1][1]) + h[i][2];
	}

	cout << min(min(a[n][0], a[n][1]), a[n][2]);

	return 0;
}
