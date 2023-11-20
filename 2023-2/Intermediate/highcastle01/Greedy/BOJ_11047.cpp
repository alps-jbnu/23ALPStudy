#include<bits/stdc++.h>

using namespace std;

int arr[10];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, i, ans = 0, sum = 0;

	cin >> n >> k;

	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for(i = n - 1; i >= 1; i--)
	{
		int cnt = (k - sum) / arr[i];
		ans += cnt;
		sum += cnt * arr[i];
	}

	ans += k - sum;

	cout << ans;

	return 0;
}
