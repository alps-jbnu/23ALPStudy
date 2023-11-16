#include<bits/stdc++.h>

using namespace std;

long long DP[101][10];

void dp(int n)
{
	int i, j;
	long long ans = 0;

	for(i = 1; i <= 9; i++)
	{
		DP[1][i] = 1;
	}
	for(i = 2; i <= n; i++)
	{
		for(j = 0; j <= 9; j++)
		{
			if(j == 0)
			{
				DP[i][j] = DP[i-1][1];
			}
			else if(j == 9)
			{
				DP[i][j] = DP[i-1][8];
			}
			else
			{
				DP[i][j] = DP[i-1][j-1] + DP[i-1][j+1];
			}

			DP[i][j] = DP[i][j] % 1000000000;
		}
	}

	for(i = 0; i <= 9; i++)
	{
		ans = ans + DP[n][i];
	}
	ans = ans % 1000000000;
	cout << ans << "\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	dp(n);

	return 0;
}
