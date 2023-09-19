#include <iostream>
using namespace std;

int arr[100'005];
int ans[2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int start = 0;
	int end = n - 1;
	int minimum = 0x7fffffff;
	int temp;
	while (start < end)
	{
		temp = arr[start] + arr[end];
		if (minimum >= abs(temp))
		{
			minimum = abs(temp);
			ans[0] = arr[start];
			ans[1] = arr[end];
		}
		if (temp < 0)
			start++;
		else
			end--;
	}
	cout << ans[0] << ' ' << ans[1];

	return 0;
}
