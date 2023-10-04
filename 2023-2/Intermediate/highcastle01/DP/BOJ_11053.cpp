#include<bits/stdc++.h>

using namespace std;

int alist[1001];
int DP[1001];

void dp(int a)
{
	int ans = 0, i, j;
	for(i = 1; i <= a; i++)
	{
		DP[i] = 1;
		for(j = i-1; j >= 1; j--)
		{
			if(alist[i] > alist[j])
			{
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		ans = max(DP[i], ans);
	}

	cout << ans;
}

int main(void)
{
	int a, i;

	cin >> a;

	for(i = 1; i <= a; i++)
	{
		cin >> alist[i];
	}

	dp(a);

	return 0;
}
