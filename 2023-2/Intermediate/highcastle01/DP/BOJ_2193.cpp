#include<bits/stdc++.h>
using namespace std;

long long DP[91];

void dp(int n)
{
	DP[1] = 1;
	DP[2] = 1;

	for(int i = 3; i <= n; i++)
	{
		DP[i] = DP[i-1] + DP[i-2];
	}

	cout << DP[n] << "\n";
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
