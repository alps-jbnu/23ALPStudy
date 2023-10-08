#include<bits/stdc++.h>

using namespace std;

int arr[1000001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, i, j;

	cin >> t;

	while(t--)
	{
		long long sum = 0;
		int maxs = 0;
		memset(arr, 0, sizeof(arr));

		cin >> n;
		for(i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		for(i = n-1; i >= 0; i--)
		{
			if(arr[i] < maxs)
			{
				sum += (maxs - arr[i]);
			}
			else
			{
				maxs = arr[i];
			}
		}

		cout << sum << "\n";
	}

	return 0;
}
