#include<bits/stdc++.h>

using namespace std;

int tree[1000001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, m, i;

	cin >> n >> m;

	for(i = 0; i < n; i++)
	{
		cin >> tree[i];
	}

	sort(tree, tree + n);

	long long start = 0, end = tree[n-1], ans = 0;

	while(start <= end)
	{
		long long mid = (start + end) / 2;
		long long tsum = 0;

		for(i = 0; i < n; i++) 
		{
            if(tree[i] > mid) 
            {
                tsum += tree[i] - mid;
            }
        }

		if(tsum >= m)
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << ans;

	return 0;
}
