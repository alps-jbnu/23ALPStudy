#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<memory.h>
using namespace std;
int arr[60010];
int vis[60010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, d, k, c;
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int mx = 0;
	int en = 0;
	int cnt = 0;
	int coupon = 1;
	for (int st = 0; st < n; st++) {
		while (en < st + k) {
			//먹어본적 있다면 카운트
			if (vis[arr[en % n]] != 0) {
				cnt++;
			}
			//먹어봤다 체크
			vis[arr[en % n]]++;
			//쿠폰체크
			if (arr[en % n] == c) {
				coupon = 0;
			}
			en++;
		}
		mx = max(mx, k - cnt + coupon);

		vis[arr[st]]--;
		if (vis[arr[st]] != 0) {
			cnt--;
		}
		else {
			if (arr[st] == c) {
				coupon = 1;
			}
		}
	}
	cout << mx;
}
