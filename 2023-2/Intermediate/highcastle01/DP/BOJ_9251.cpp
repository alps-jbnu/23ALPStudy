#include<bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i, j;
	string str1, str2;

	cin >> str1 >> str2 ;

	for(i = 1; i <= str1.size(); i++)
	{
		for(j = 1; j <= str2.size(); j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[str1.size()][str2.size()];

	return 0;
}
