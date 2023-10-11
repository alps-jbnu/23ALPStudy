#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[100'005];
int dp[100'005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);		// 현재 값과 이전 값들의 합 중 더 큰 것을 저장
	cout << *max_element(dp + 1, dp + 1 + n);
	return 0;
}
