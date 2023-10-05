#include<bits/stdc++.h>

using namespace std;

int arr[30001];
int check[3001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, d, k, c, i;

	cin >> n >> d >> k >> c;

	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int start = 0, end = k - 1, cnt = 0, ans = 0;

  //초밥 종류 카운트
	for(i = 0; i < k; i++)
	{
		check[arr[i]]++;
		if(check[arr[i]] == 1)
		{
			cnt++;
		}
	}

	check[c]++;
	if(check[c] == 1)
	{
		cnt++;
	}
  //초밥종료 카운트 끝

	while(start < n)
	{
		ans = max(ans, cnt);
		if(--check[arr[start++]] == 0)
		{
			cnt--;
		}

		end = (end + 1) % n;
		if(++check[arr[end]] == 1)
		{
			cnt++;
		}
	}

	cout << ans;

	return 0;
}
