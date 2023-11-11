#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		for (int j = 0; j <= i; j++)
			temp += arr[j];
		ans += temp;
	}
	cout << ans;
	return 0;
}
