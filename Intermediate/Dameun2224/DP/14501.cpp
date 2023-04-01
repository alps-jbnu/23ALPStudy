#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int a[20][2];
int d[20];
int n;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
		d[i] = a[i][1];
	}


	d[1] = a[1][1];
	int ans;
	if (n < a[1][0]) ans = 0;
	else ans = d[1];
	for (int i = 2; i <= n; i++) {
		if (n - i + 1 < a[i][0]) continue;
		for (int j = i - 1; j >= 1; j--) {
			if (i - j < a[j][0]) continue;
			d[i] = max(d[i], d[j] + a[i][1]);
		}
		ans = max(d[i], ans);
	}

	cout << ans << '\n';


	return 0;
}
