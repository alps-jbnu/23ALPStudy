#include<bits/stdc++.h>
using namespace std;


int t;
int n;
long long num[9] = { 0,0,1,7,4,2,0,8,10 };
long long dp[101] = { 0,0,1,7,4,2,6,8,10 };



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	for (int i = 9; i <= 100; i++) {
		dp[i] = LLONG_MAX;
		for (int j = 2; j < 8; j++) {
			dp[i] = min(dp[i- j] * 10+num[j], dp[i]);
		}
	}


	while (t--) {
		cin >> n;
		
		cout << dp[n] << ' ';
		if (n % 2 == 0) {
			n /= 2;
			while (n--)	cout << 1;
		}
		else {
			cout << 7;
			n = n / 2 - 1;
			while (n--)	cout << 1;
		}
		cout << '\n';
	}
 }