#include <iostream>
using namespace std;

int arr[100'005];
bool vis[100'005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int end = 0;
	long long sum = 0;
	for (int start = 0; start < n; start++)
	{
		while (end < n)
		{
			if (vis[arr[end]])
				break;
			vis[arr[end]] = true;
			end++;
		}
		sum += (end - start);
		vis[arr[start]] = false;
	}
	cout << sum;
	return 0;
}
