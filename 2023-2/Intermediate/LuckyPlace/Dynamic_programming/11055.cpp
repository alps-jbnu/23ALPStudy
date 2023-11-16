#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[1005];
int dp[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}
	// 한 칸 움직일 때마다 앞의 칸들을 돌며 가장크고 증가하는 경우만 저장
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (arr[i] > arr[j])
				dp[i] = max(dp[j] + arr[i], dp[i]);
	cout << *max_element(dp + 1, dp + 1 + n);


	return 0;
}
