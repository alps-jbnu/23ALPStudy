#include<bits/stdc++.h>

using namespace std;

int arr[100001];
int check[100001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i;
	long long n, ans;

	cin >> n;

	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	ans = n * (n+1) / 2; //모든 수열의 개수 저장

	int start = 0, end = 1;
	check[arr[start]] = 1;

	while(end < n)
	{
		if(check[arr[end]])
		{
			check[arr[start]] = 0; //다시 검색되지않
			start++;
			ans -= n - end;
		}
		else
		{
			check[arr[end]] = 1;
			end++;
		}
	}

	cout << ans;

	return 0;
}
