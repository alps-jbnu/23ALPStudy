#include <iostream>
#include <cmath>
using namespace std;

int arr[100'000'005];

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
	int ans = 0x7fffffff;
	while (start < end)
	{
		int temp = arr[start] + arr[end];
		if (abs(ans) > abs(temp))
			ans = temp;
		if (temp > 0)
			end--;
		else
			start++;
	}
	cout << ans;
	
	return 0;
}
