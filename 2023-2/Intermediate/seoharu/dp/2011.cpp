// 2511 

// dp[n] += dp[n-1] + dp[n-2]
//  dp[n-1] 에서 1 <= arr[n] <= 9
// dp[n-2]에서 10 <= arr[n-1]*10 + arr[n] <= 26

#include <iostream>
#include <string>
#define mod 1000000;         // 정답 : modu로 나눈 나머지 출력

std::string str;
int len;
int dp[5001];             // 5000자리 이하의 암호 
int arr[5001];

int main()
{
	std::cin >> str;
	len = str.length();

	for (int i = 1; i <= len; i++)
		arr[i] = str[i - 1] - '0';

	dp[0] = 1;

	for (int i = 1; i <= len; i++)
	{
		if (arr[i] >= 1 && arr[i] <= 9)
			dp[i] = (dp[i - 1] + dp[i]) % mod;
	
		if (i == 1)
			continue;  
		int con = arr[i - 1] * 10 + arr[i];
		if (con >= 10 && con <= 26)
			dp[i] = (dp[i - 2] + dp[i]) % mod;
	}
	if (len == 1 && str[0] == '0')
		std::cout << 0 << "\n";
	else
		std::cout << dp[len];
}
