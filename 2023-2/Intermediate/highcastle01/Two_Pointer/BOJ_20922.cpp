#include<bits/stdc++.h>

using namespace std;

int arr[2000001];
int check[100001];

int main(void)
{
	int n, k, i, j;

	cin >> n >> k;

	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int start = 0, end = 0, ans = 0, tmp = 0;

	while(start <= end && end < n)
	{
		if(check[arr[end]] < k)
		{
			check[arr[end++]]++;
			ans = max(ans, end - start);
		}
		else if(check[arr[end]] == k)
		{
			check[arr[start++]]--;
		}
	}

	cout << ans;

	return 0;
}

//처음엔 arr[start]랑 arr[end]의 값이 다르면 start와 end 둘다 이동, 같으면 end만 이동해서 end - start의 거리차이가 k보다 많이 나면
//될 수 있을 거 같았는데.. 이게 겹치는 숫자가 하나면 모르겠지만 여러개가 되면 이상해짐.

// int arr[2000001];

// int main(void)
// {
// 	int n, k, i, j;

// 	cin >> n >> k;

// 	for(i = 0; i < n; i++)
// 	{
// 		cin >> arr[i];
// 	}

// 	int start = 0, end = 1, ans = 0, tmp = 0;

// 	while(end < n)
// 	{
// 		if(arr[end] != arr[start])
// 		{
// 			start++;
// 			end++;
// 			tmp++;
// 		}
// 		else
// 		{
// 			if(end - start == k)
// 			{
// 				start = end;
// 				ans = max(ans, tmp);
// 				tmp = 0;
// 			}
// 			else
// 			{
// 				end++;
// 				tmp++;
// 			}
// 		}
// 	}

// 	cout << ans;

// 	return 0;
// }
