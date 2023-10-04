#include <iostream>
#include <cmath>
using namespace std;

long long dp[95][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	dp[1][1] = 1;
	for(int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];		// 끝자리가 0인 경우는 이전 자리가 0, 1인 경우 모두 가능
		dp[i][1] = dp[i - 1][0];		// 끝자리가 1인 경우는 이전 자리가 0인 경우만 가능
	}
	cout << dp[n][0] + dp[n][1];
	return 0;
}
