#include<bits/stdc++.h>

using namespace std;

int DP[16];
int T[1001];
int P[1001];

void dp(int n)
{
	int maxnum = 0;
	for(int i = 0; i <= n; i++)
	{
		DP[i] = max(maxnum, DP[i]);
		if(T[i] + i <= n)
		{
			DP[T[i] + i] = max(DP[T[i] + i], P[i] + DP[i]);
		}
		maxnum = max(maxnum, DP[i]);
	}
	cout << maxnum;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, i;

	cin >> n;

	for(i = 0; i < n; i++)
	{
		cin >> T[i] >> P[i];
	}

	dp(n);

	return 0;
}
