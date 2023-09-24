#include <iostream>
using namespace std;

int arr[200'005];
int vis[100'005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int start = 0;
	int max_len = 0;
	for (int end = 0; end < n; end++)
	{
		vis[arr[end]]++;
		while (vis[arr[end]] > k)
		{
			vis[arr[start]]--;
			start++;
		}
		max_len = max(max_len, (end - start) + 1);
	}
	cout << max_len;
	return 0;
}
