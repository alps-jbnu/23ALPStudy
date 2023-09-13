#include<bits/stdc++.h>

using namespace std;

int havearr[500001];
int checkarr[500001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, i, j;

	cin >> n;

	for(i = 0; i < n; i++)
	{
		cin >> havearr[i];
	}

	cin >> m;

	sort(havearr, havearr + n);

	for(i = 0; i < m; i++)
	{
		int x;
		int start = 0, end = n - 1;

		cin >> x;

		while(start <= end)
		{
			int mid = (start + end) / 2;

			if(x == havearr[mid])
			{
				checkarr[i] = 1;
				break;
			}
			
			if(x > havearr[mid])
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
	}

	for(i = 0; i < m; i++)
	{
		cout << checkarr[i] << " ";
	}

	return 0;
}
