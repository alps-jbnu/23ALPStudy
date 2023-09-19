#include <iostream>
#include <cmath>		//for abs()
#include <algorithm>
using namespace std;

long long arr[5005];
long long result[3];
long long ans = 9223372036854775807;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	// i를 고정시키고 l, r만 움직이는 투 포인터 방식으로 풀 수 있다.
	for (int i = 0; i < n - 2; i++)
	{
		int l = i + 1;
		int r = n - 1;
		while (l < r)
		{
			long long temp = arr[i] + arr[l] + arr[r];
			if (abs(temp) < ans)
			{
				ans = abs(temp);
				result[0] = arr[i];
				result[1] = arr[l];
				result[2] = arr[r];
			}
			if (temp == 0)
			{
				sort(result, result + 3);
				for (int i = 0; i < 3; i++)
					cout << result[i] << ' ';
				return 0;
			}
			if (temp < 0)
				l++;
			else
				r--;
		}
	}
	sort(result, result + 3);
	for (int i = 0; i < 3; i++)
		cout << result[i] << " ";

	return 0;
}
