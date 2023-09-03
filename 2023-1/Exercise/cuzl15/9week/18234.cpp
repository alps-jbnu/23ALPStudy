#include<bits/stdc++.h>
using namespace std;

int n, t;
long long ans = 0;
pair<long long, long long> arr[2000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		ans += arr[i].second + arr[i].first * (t - n + i);
	}
	cout << ans;
}