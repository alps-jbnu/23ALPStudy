#include<bits/stdc++.h>

using namespace std;

int dp[31] = {1, 0, 3};

void DP(int n)
{
	for(int i = 4; i <= n; i = i+2)
	{
		dp[i] = dp[i - 2] * dp[2];
		for(int j = i-4; j >= 0; j = j-2)
		{
			dp[i] = dp[i] + (dp[j] * 2);
		}
	}

	cout << dp[n];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	DP(n);

	return 0;
}
