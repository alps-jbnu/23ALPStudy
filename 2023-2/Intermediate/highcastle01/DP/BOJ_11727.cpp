#include<iostream>

using namespace std;

int DP[1001] = {0, 1, 3};

void dp(int n)
{
	for(int i = 3; i <= n; i++)
	{
		DP[i] = (DP[i-1] + 2 * DP[i-2]) % 10007;
	}

	cout << DP[n];
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
