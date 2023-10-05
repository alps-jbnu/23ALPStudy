#include<bits/stdc++.h>

using namespace std;

int snack[1000001];

int check(int x)
{//최적의 값을 찾기 위해 mid값이 들어오면 mid값으로 나눈 배열의 값들을 더해서 리턴해줌(이렇게 하면 최대길이를 보장해 줄 수 있음.)
	int cnt = 0;
	for(auto i : snack)
	{
		cnt += i / x;
	}

	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, i, j;

	cin >> m >> n;

	for(i = 0; i < n; i++)
	{
		cin >> snack[i];
	}

	sort(snack, snack + n);

	int left = 1, right = snack[n-1], mid, ans = 0;

	while(left <= right)
	{
		mid = (left + right) / 2;

		if(m <= check(mid))
		{
			left = mid + 1;
			ans = mid;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans;

	return 0;
}
