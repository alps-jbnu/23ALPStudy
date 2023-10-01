#include <iostream>
using namespace std;

int arr[1'000'005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		long long ans = 0;				// int면 오답
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> arr[j];
		int cur_max = arr[n - 1];
		for (int j = n - 2; j >= 0; j--)
		{
			if (arr[j] < cur_max)
				ans += cur_max - arr[j];		// 현재가 최대일 경우 ans에 더함
			else
				cur_max = arr[j];					// 아닐 경우 최댓값 갱신
		}
		cout << ans << "\n";
	}

	return 0;
}
