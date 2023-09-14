#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

long long int n, m;
long long int num[1000005];
long long int sum[1000005];
long long int d[1005];


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

	long long int ans = 0;
	for (int i = 0; i < m; i++)
		for (int j = 1; j < d[i]; j++)
			ans += j;
	ans += d[0];

	cout << ans << '\n';

	return 0;
}
