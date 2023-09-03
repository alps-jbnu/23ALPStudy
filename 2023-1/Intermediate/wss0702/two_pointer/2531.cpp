#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//È¸Àü ÃÊ¹ä
using namespace std;

int N, d, k, c;

int arr[30002];
bool cnt[3002]; // °ãÄ¡´Â ÃÊ¹äÀÇ °³¼ö
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> d >> k >> c;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int count = 0;
	int ans = 0;
	bool coupon = false;
	for (int st = 0; st < N; st++) {
		for (int en = 0; en < k; en++) {
			int eatsushi = arr[(st + en) % N];
			if (eatsushi == c) coupon = true;
			if (!cnt[eatsushi]) {
				count++;
				cnt[eatsushi] = true;
			}
		}
		if (!coupon) ans = max(ans, count + 1);
		else ans = max(ans, count);
		coupon = false;
		count = 0;
		for (int i = 0; i <= d; i++) cnt[i] = false;
	}
	cout << ans;
}
