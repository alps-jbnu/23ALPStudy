#include<bits/stdc++.h>
using namespace std;


int cnt[10001] = {}, sz = 0;
bool pr[500001];
vector<int> candy;
int n,mx=0;
long long dp[500001] = { 1, };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 2; i < 500001; i++) {
		if (pr[i])	continue;
		for (int j = i *2; j < 500001; j += i) {
			pr[j] = 1;
		}
	}

	int zero = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		if (d == 0) {
			zero++;
			continue;
		}
		if (cnt[d] == 0) {
			candy.push_back(d);
		}
		cnt[d]++;
	}
	int s = candy.size();
	for (int i = 0; i < s; i++) {
		for (int j = mx; j >= 0; j--) {
			for (int k = 1; k <= cnt[candy[i]];k++) {
				if (j + k * candy[i] >= 500001)	break;
				dp[j + k * candy[i]] += dp[j];
			}
		}
		mx += candy[i] * cnt[candy[i]];
		mx = min(mx, 500000);
	}
	long long ans = 0;
	for (int i = 2; i < 500001; i++) {
		if (!pr[i])	ans += dp[i];
	}
	ans *= zero;
	cout << ans;
 }