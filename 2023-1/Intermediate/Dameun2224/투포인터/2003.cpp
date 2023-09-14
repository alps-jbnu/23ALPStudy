#include <iostream>
#include <algorithm>
using namespace std;

int arr[10005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int st = 0, en = 0;
	int sum = 0, ans = 0;
	while (st < n) {
		while (en < n && sum < m) sum += arr[en++];
		if (sum == m) ans++;
		sum -= arr[st++];
		if (en == n) {
			if (sum == m) ans++;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}
