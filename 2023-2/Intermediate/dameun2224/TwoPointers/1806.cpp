#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int arr[100005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int st = 0, en = 0, sum = 0, ans = INT_MAX;
	for (st = 0; st < n; st++) {
		while (en < n && sum < s) {
			sum += arr[en];
			en++;
		}
		if (en == n + 1) break;
		if (sum >= s) ans = (ans < en - st) ? ans : en - st;
		sum -= arr[st];
	}

	if (ans == INT_MAX) ans = 0;
	cout << ans << '\n';

	return 0;
}
