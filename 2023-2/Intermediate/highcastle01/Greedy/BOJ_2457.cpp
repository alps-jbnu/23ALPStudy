#include<bits/stdc++.h>

using namespace std;

#define E first
#define S second
//끝나는 날 정렬 위해서

pair<int, int> arr[100001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, i, overCheck = 0, underCheck = 1230;

	cin >> n;

	for(i = 0; i < n; i++)
	{
		int sm, sd, em, ed;

		cin >> sm >> sd >> em >> ed;

		arr[i].S = sm*100 + sd;
		arr[i].E = em*100 + ed;

		if(overCheck < arr[i].E)
		{
			overCheck = arr[i].E;
		}
		if(underCheck > arr[i].S)
		{
			underCheck = arr[i].S;
		}
	}

	if(underCheck > 301 || overCheck <= 1130)
	{
		cout << 0;
		return 0;
	}

	sort(arr, arr+n);

	int t = 301;
	int ans = 0;

	while(t < 1201)
	{
		int nxt = t;
		for(i = 0; i < n; i++)
		{
			if(arr[i].S <= t && arr[i].E > nxt)
			{
				nxt = arr[i].E;
			}
		}
		if(nxt == t)
		{
			cout << 0;
			return 0;
		}
		ans++;
		t = nxt;
	}

	cout << ans;

	return 0;
}
