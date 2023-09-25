#include <iostream>
#include <algorithm>
using namespace std;

int arr[10'005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int start = 0;
	int sum = 0;
	int ans = 0;
	for (int end = 0; end < n; end++)
	{
		sum += arr[end];
		if (sum < m)
			continue;
		else if (sum == m)
			ans++;
		else
		{
			while (sum > m)
			{
				sum -= arr[start];
				start++;
				if (sum == m)
					ans++;
			}
		}
	}
	cout << ans;

	return 0;
}
