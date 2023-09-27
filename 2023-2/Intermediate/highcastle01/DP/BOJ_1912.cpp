#include<bits/stdc++.h>

using namespace std;

int arr[100001];
int DP[100001];

void dp(int n)
{
	int ans = arr[1];
	DP[1] = arr[1];

	for(int i = 2; i <= n; i++)
	{
		if(DP[i-1] + arr[i] < arr[i])
		{
			DP[i] = arr[i];
			ans = max(ans, DP[i]);
		}
		else
		{
			DP[i] = DP[i-1] + arr[i];
			ans = max(ans, DP[i]);
		}
	}

	cout << ans;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, i;

	cin >> n;

	for(i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp(n);

	return 0;
}
