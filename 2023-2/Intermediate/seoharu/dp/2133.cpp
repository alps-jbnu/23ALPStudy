
// 2133

#include <iostream>

int n;
int dp[35];

int main()
{
	std::cin >> n;
	
	dp[0] = 1;      // 식 계산 위한
	dp[1] = 0;
	dp[2] = 3;
	if (n % 2 == 1)
		std::cout << 0 << "\n";

	else
	{
		for (int i = 4; i <= n; i += 2)
		{
			dp[i] = dp[i - 2] * dp[2];
			for (int j = i - 4; j >= 0; j -= 2)
				dp[i] += dp[j] * 2;
		}
		std::cout << dp[n] << "\n";
	}
}
