#include<bits/stdc++.h>
using namespace std;
int n, k;
int sum = 0;
int arr[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	int l = 0, r = sum;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 0;
		int ss = 0;
		for (int i = 0; i < n; i++) {
			ss += arr[i];
			if (ss >= mid) {
				++cnt;
				ss = 0;
			}
		}
		if (cnt >= k) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
}