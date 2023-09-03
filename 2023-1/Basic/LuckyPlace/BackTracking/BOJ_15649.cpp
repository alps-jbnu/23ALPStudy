#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool is_used[10];

void back_tracking(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!is_used[i])
		{
			arr[k] = i;
			is_used[i] = true;
			back_tracking(k + 1);
			is_used[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	back_tracking(0);
	return 0;
}