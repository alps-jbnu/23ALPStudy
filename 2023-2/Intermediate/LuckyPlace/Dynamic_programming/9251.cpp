#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string str1, str2;
int dp[1005][1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str1 >> str2;
	/*A C A Y K P
	C 0 1 1 1 1 1
	A 1 1 1 2 2 2
	P 1 2 2 2 3 3
	C 1 2 2 2 3 3
	A 1 2 2 2 3 4
	K 1 2 3 3 3 4*/
	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[str1.size()][str2.size()];

	return 0;
}
