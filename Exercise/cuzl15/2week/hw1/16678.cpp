#include<bits/stdc++.h>
using namespace std;


int n;
int arr[100005];
long long ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	
	int idx = 0;
	int cnt = 1;
	while (idx < n) {
		if (arr[idx] == cnt) {
			while (arr[idx] == cnt) {
				++idx;
			}
		}
		else {
			ans += arr[idx] - cnt;
			++idx;
		}
		++cnt;
	}
	cout << ans;
 }