#include <iostream>
#include <cmath>
using namespace std;

int arr[501][501];
int dp[501][501];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (max < dp[n][i])
			max = dp[n][i];
	}
	cout << max;
	return 0;
}
