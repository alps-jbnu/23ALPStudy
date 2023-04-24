#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a[100005];
int n, ans;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	// 내림차순 정렬
	sort(a, a + n, greater<int>());
	for (int i = 0; i < n; i++) {
		ans = max(a[i] * (i + 1), ans);
	}

	cout << ans << '\n';

	return 0;
}
