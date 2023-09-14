#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long dp[105];// 자료형 범위 주의
int T,n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	for (int i = 7; i <= 100; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}
