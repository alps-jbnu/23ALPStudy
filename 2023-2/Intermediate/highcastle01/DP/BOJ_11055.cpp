#include<bits/stdc++.h>

using namespace std;

int alist[1001];
int dp[1001];

void DP(int a)
{
	int ans = 0, i, j;

	for(i = 1; i <= a; i++)
	{
		dp[i] = alist[i];
		for(j = 1; j < i; j++)
		{
			if(alist[i] > alist[j] && dp[i] < dp[j] + alist[i])
			{
				dp[i] = dp[j] + alist[i];
			}
		}
		ans = max(dp[i], ans);
	}

	cout << ans;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, i;

	cin >> a;

	for(i = 1; i <= a; i++)
	{
		cin >> alist[i];
	}

	DP(a);

	return 0;
}
