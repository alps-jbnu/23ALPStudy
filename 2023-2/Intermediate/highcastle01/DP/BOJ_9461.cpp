#include<bits/stdc++.h>

using namespace std;

long long DP[101];

void dp(int x)
{
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	DP[4] = 2;
	DP[5] = 2;

	for(int i = 6; i <= x; i++)
	{
		DP[i] = DP[i-1] + DP[i-5];
	}

	cout << DP[x] << "\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, i, x;

	cin >> n;

	while(n--)
	{
		cin >> x;
		dp(x);
	}

	return 0;
}
