#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, ans;
int a[55], b[55];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(a, a + n);
	sort(b, b + n, greater<int>());

	for (int i = 0; i < n; i++) ans += a[i] * b[i];
	cout << ans << '\n';

	return 0;
}
