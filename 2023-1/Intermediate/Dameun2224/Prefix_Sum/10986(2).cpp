#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

long long int n, m;
long long int num[1000005];
long long int sum[1000005];
long long int d[1005];
long long int a[1000005];


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + num[i - 1];
		d[sum[i] % m]++;
	}

	a[2] = 1;
	for (int i = 3; i <= n; i++)
		a[i] = a[i - 1] + (i - 1);

	long long int ans = 0;
	for (int i = 0; i < m; i++)
		ans += a[d[i]];
	ans += d[0];

	cout << ans << '\n';

	return 0;
}
