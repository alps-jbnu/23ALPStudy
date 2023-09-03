#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long dp[95][2];// 자료형 범위 주의
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];//0전에 1이 나오든 0이 나오든 상관없음.
		dp[i][1] = dp[i - 1][0];//1이 나오기 이전에 무조건 0이어야함
	}
	
	cout << dp[n][0] + dp[n][1];
}
