#include<bits/stdc++.h>
using namespace std;

int arr[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a]++;
	}
	int ans1 = 1, ans2 = 1;
	long long minSum1 = LLONG_MAX, minSum2 = LLONG_MAX, sum1, sum2;
	for (int i = 1; i <= 10000; i++) {
		sum1 = 0;
		for (int j = 1; j <= 10000; j++) {
			sum1 += 1LL*arr[j] * abs(i - j);
		}
		if (sum1 < minSum1) {
			minSum1 = sum1;
			ans1 = i;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		sum2 = 0;
		for (int j = 1; j <= 10000; j++) {
			sum2 += 1LL*arr[j] * (i - j) * (i - j);
		}
		if (sum2 < minSum2) {
			minSum2 = sum2;
			ans2 = i;
		}
	}
	cout << ans1 << ' ' << ans2;
 }