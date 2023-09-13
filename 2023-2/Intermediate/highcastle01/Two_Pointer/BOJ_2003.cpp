#include<bits/stdc++.h>

using namespace std;

int a[10001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, i, j, cnt = 0, sum = 0, left = 0, right = 0;

	cin >> n >> m;

	for(i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	while(right <= n)
	{
		if(sum < m)
		{//값이 작으면 계속 넣어준다.
			sum += a[right++];
		}
		if(sum >= m)
		{// 값이 크거나 같은 경우
			if(sum == m)
			{//같으면 갯수를 세준다.
				cnt++;
			}//크면 값이시작된(left) 부분 빼주고 왼쪽으로 커서를 이동시켜준다.
			sum -= a[left++];
		}
	}

	cout << cnt;
}
