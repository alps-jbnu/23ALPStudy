#include<bits/stdc++.h>

using namespace std;

int dp[41];

void fibo(int n)
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3; i <= n; i++)
	{
		dp[i] = dp[i-2] + dp[i-1];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, i;

	fibo(41);

	cin >> t;

	for(i = 0; i < t; i++)
	{
		int n;

		cin >> n;
		if(n == 0)
		{
			cout << 1 << " " << 0 << "\n";
		}
		else if(n == 1)
		{
			cout << 0 << " " << 1 << "\n";
		}
		else
		{
			cout << dp[n-1] << " " << dp[n] << "\n";
		}
	}

	return 0;
}
