#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int d[305][2];
int s[305];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];

	d[1][0] = d[1][1] = s[1];
	d[2][0] = s[2];
	d[2][1] = d[1][0] + s[2];

	for (int i = 3; i <= n; i++) {
		d[i][0] = max(d[i - 2][0], d[i - 2][1]) + s[i];
		d[i][1] = d[i - 1][0] + s[i];
	}

	cout << max(d[n][0], d[n][1]) << '\n';

	return 0;
}
