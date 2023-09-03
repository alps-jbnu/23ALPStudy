#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
// for문 범위 잘 정하기
using namespace std;
int dp[16];
int n;
int T[16];
int P[16];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = n; i >= 1; i--) {
		if (i + T[i] <= n + 1/*퇴사하는 날을 넘기면 안됨*/) {
			dp[i] = max(dp[i + T[i]] + P[i]/*상담하고 나선 이익금 + 그 후에 최대 이익*/, dp[i + 1]/*상담 넘기기*/);
		}
		else dp[i] = dp[i + 1];
	}
	cout << *max_element(dp, dp + n + 1);
}
